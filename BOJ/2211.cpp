// 네트워크 복구
// https://www.acmicpc.net/problem/2211

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pr>> board(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	vector<int> dist(n + 1, 987654321), road(n + 1, -1);
	priority_queue<pr> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int len = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (pr p : board[cur]) {
			int next = p.first;
			int nlen = p.second;
			if (dist[next] > len + nlen) {
				dist[next] = len + nlen;
				road[next] = cur;
				pq.push({ -dist[next], next });
			}
		}
	}
	vector<bool> visit(n + 1);
	vector<pr> res;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			int p = i;
			while (road[p] != -1) {
				if (visit[p])
					break;
				visit[p] = true;
				res.push_back({ p, road[p] });
				p = road[p];
			}
		}
	}
	cout << res.size() << '\n';
	for (pr p : res)
		cout << p.first << ' ' << p.second << '\n';
}

// n개의 컴퓨터와 가중치가 다른 m개의 선으로 구성된 네트워크를 복구하는데 최소 회선만 복구하고 원래 네트워크에서의 통신 시간 이하를 유지하려고 할 때, 남길 수 있는 선의 개수와 종류는?

// 다익스트라로 최단 거리와 이에 소속된 선들을 구한 뒤 출력하기
// MST 문제는 아님 - MST로 얻어지는 최소 간선들이 슈퍼컴퓨터와 다른 컴퓨터의 최단 경로라고 말할 수는 없음
// 이를 위해 다익스트라에서 거리가 갱신될 때 해당 위치로 온 노드를 road 배열에 저장해주기
// 어차피 초기 상태에서 모든 컴퓨터가 연결되어 있음이 보장되고, 최단거리 기준도 슈퍼컴퓨터(1번) 기준임
// 따라서 다익스트라도 1번을 기준으로 한 번만 돌리면서, road를 갱신시켜 나가기
// 이후 road 배열을 적절히 순회하여 필요한 간선을 저장하고(순서 및 방향 무관), 이들의 개수와 모양을 출력하기
// 이를 위해 road[p]가 -1이 될 때까지 {p, road[p]}를 저장해갈 수 있음 - 여기서 visit를 활용해 visit[p]라면 중복된 노드니 들어가지 않도록