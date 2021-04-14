// 노드사이의 거리
// https://www.acmicpc.net/problem/1240

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
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	for (int i = 0; i < m; i++) {
		int s, d;
		cin >> s >> d;
		vector<bool> visit(n + 1);
		queue<pr> q;
		q.push({ s, 0 });
		visit[s] = true;
		while (!q.empty()) {
			int p = q.front().first;
			int dist = q.front().second;
			q.pop();
			if (p == d) {
				cout << dist << '\n';
				break;
			}
			for (pr r : board[p]) {
				if (!visit[r.first]) {
					visit[r.first] = true;
					q.push({ r.first, r.second + dist });
				}
			}
		}
	}
}

// 간선 별로 길이가 다른 트리에서 두 노드 간의 거리 구하기
// 간선 길이를 고려한 최단 거리를 구하는 문제가 아님 - 물리적 최단 거리를 구하는 bfs로 접근해야 함
// 그러니까 일반적인 bfs를 돌면서 그 안에 있는 간선의 합을 구하라는 것