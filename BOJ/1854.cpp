// K번째 최단경로 찾기
// https://www.acmicpc.net/problem/1854

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pr>> board(n + 1);
	vector<priority_queue<int>> dist(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
	}
	priority_queue<pr> pq;
	dist[1].push(0);
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int len = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (pr p : board[cur]) {
			if (dist[p.first].size() < k) {
				dist[p.first].push(len + p.second);
				pq.push({ -(len + p.second), p.first });
			}
			else if (dist[p.first].top() > len + p.second) {
				dist[p.first].pop();
				dist[p.first].push(len + p.second);
				pq.push({ -(len + p.second), p.first });
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << (dist[i].size() == k ? dist[i].top() : -1) << '\n';
}

// 가중치가 있는 단방향 도로로 이어진 도시들에서 1번 도시에서 각 도시로 가는 k번째 최단 경로의 거리 출력하기
// 다익스트라를 응용해야 함 - k번째 최단 경로를 찾기 위해 dist 배열이 각각의 우선순위 큐(최대 힙)를 가지고 있어야 함
// 다익스트라에서 '최단거리일 경우 갱신 후 pq 삽입' 부분을 '거리 저장 후 pq 삽입'으로 변경 - 모든 경우의 거리 체크
// 다만 무조건 삽입했다가 사이클을 만나버리면 끝없이 돌아버릴 수 있기에 각 dist pq에 k만큼의 거리가 쌓이면 종전처럼 최단거리를 기준으로 삽입하기
// = 내 dist pq에 가장 위에 있는(후보군 중 가장 긴) 거리보다 지금 거리가 더 짧은 경우 그걸 빼고 지금 거리를 넣기
// 나에서 나에게 오는 거리는 0이기에 dist[1]에 0 삽입하고 스타트
// pq 돌린 후 dist의 크기가 k라면 top, 그렇지 않으면 -1 출력
// pq와 dist에서 돌리는 힙 종류가 다름에 주의
// 그런데 어디서 보니까 다익스트라로 돌리는 경로 순서가 곧 k번째 최소 경로라는 말도 있던데...?