// 텔레포트 정거장
// https://www.acmicpc.net/problem/18232

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m, s, e;
	cin >> n >> m >> s >> e;
	vector<vector<int>> board(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			board[i].push_back(i - 1);
		}
		if (i != n) {
			board[i].push_back(i + 1);
		}
	}
	vector<int> visit(n + 1, -1);
	visit[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == e) {
			cout << visit[e] << '\n';
			break;
		}
		for (int i : board[p]) {
			if (visit[i] == -1) {
				visit[i] = visit[p] + 1;
				q.push(i);
			}
		}
	}
}

// 1~n의 1차원 공간에서 양 옆 칸이나 m가지 텔레포트 통로를 탈 수 있을 때, s에서 e까지 가는 최단 거리 구하기

// 기본적인 1차원 bfs 문제