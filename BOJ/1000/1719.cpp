// 택배
// https://www.acmicpc.net/problem/1719

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
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 987654321));
	vector<vector<int>> res(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	for (int t = 1; t <= n; t++) {
		priority_queue<pr> pq;
		pq.push({ 0, t });
		dist[t][t] = 0;
		while (!pq.empty()) {
			int len = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (dist[t][cur] < len)
				continue;
			for (pr p : board[cur]) {
				int next = p.first;
				int nlen = p.second + len;
				if (dist[t][next] > nlen) {
					dist[t][next] = nlen;
					res[t][next] = cur;
					pq.push({ -nlen, next });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else {
				int idx = j;
				while (res[i][idx] != i)
					idx = res[i][idx];
				cout << idx << ' ';
			}
		}
		cout << '\n';
	}
}

// 간선별 가중치가 다른 그래프에서 한 지점에서 다른 지점으로 최단거리로 이동할 때 첫 번째로 도달해야 하는 지점 번호는?

// 플로이드를 쓸 수도 있지만, 문제 특성상 다익스트라를 n번 돌리는 것이 더 편리함
// 다익스트라에서 최단경로의 구성을 찾을 때 이전 노드를 기록하는 방식을 사용하는데, 이를 2차원 행렬 형태로 나타낼 수 있게 확장한 문제
// 따라서 각 출발지별로 다익스트라와 최단거리 이전 노드를 기록하여 결과지를 만든 후, 결과를 출력할 때 두 인덱스가 같으면 -, 그렇지 않으면 도착 인덱스에서 출발해 출발 인덱스 직전 노드까지 도달한 후 해당 노드를 출력하기
// 이전 노드 기록 배열 역시 2차원으로 관리 - 앞은 출발지, 뒤는 도착지