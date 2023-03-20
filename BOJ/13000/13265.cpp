// 색칠하기
// https://www.acmicpc.net/problem/13265

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		vector<int> visit(n + 1, -1);
		vector<vector<int>> board(n + 1);
		bool res = true;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			board[a].push_back(b);
			board[b].push_back(a);
		}
		queue<int> q;
		for (int r = 1; r <= n; r++) {
			if (visit[r] != -1) {
				continue;
			}
			visit[r] = 0;
			q.push(r);
			while (!q.empty()) {
				int p = q.front();
				q.pop();
				for (int i : board[p]) {
					if (visit[i] != -1) {
						continue;
					}
					visit[i] = visit[p] == 1 ? 0 : 1;
					q.push(i);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j : board[i]) {
				if (i > j) {
					continue;
				}
				if (visit[i] == visit[j]) {
					res = false;	
					break;
				}
			}
			if (!res) {
				break;
			}
		}
		cout << (res ? "possible" : "impossible") << '\n';
	}
}

// 그래프가 주어졌을 때, 연결된 두 노드를 같은 색으로 칠하지 않으면서 2가지 색으로 그래프를 칠할 수 있는지 판정하기

// 일단은 bfs로 노드를 순회하며 연결된 노드들을 무조건 다른 색으로 칠해주기
// 이후 간선들을 확인하면서 서로 다른 색으로 채워졌는지 확인한다 - 같은 색이면 실패