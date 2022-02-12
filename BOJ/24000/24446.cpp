// 알고리즘 수업 - 너비 우선 탐색 3
// https://www.acmicpc.net/problem/24446

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;

	vector<vector<int>> board(n + 1);
	vector<int> visit(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	queue<int> q;
	q.push(r);
	visit[r] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i : board[p]) {
			if (visit[i] == -1) {
				visit[i] = visit[p] + 1;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << visit[i] << '\n';
	}
}

// 그래프를 너비 우선 탐색하여 방문 단계별로 트리를 만들 때, 출발 노드(루트)부터 시작한 각 노드의 depth 출력하기

// bfs를 돌리면서 visit를 깊이로 기록하기 - 다음 노드 = 현재 노드 + 1