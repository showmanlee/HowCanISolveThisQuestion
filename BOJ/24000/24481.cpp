// 알고리즘 수업 - 깊이 우선 탐색 3
// https://www.acmicpc.net/problem/24481

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<vector<int>> board;
int visit[100001];
int cnt;

void dfs(int p, int d) {
	visit[p] = d;
	for (int i : board[p]) {
		if (visit[i] == -1) {
			dfs(i, d + 1);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> r;
	board.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(board[i].begin(), board[i].end());
		visit[i] = -1;
	}
	cnt = 0;
	dfs(r, 0);
	for (int i = 1; i <= n; i++) {
		cout << visit[i] << '\n';
	}
}

// 그래프를 깊이 우선 탐색할 때 각 노드의 깊이 출력하기

// 노드를 오름차순으로 2차원 vector의 각 vector를 정렬해두기
// 그 외에는 일반적인 DFS 기본 문제라고 볼 수 있을 듯 - dfs 함수에 깊이도 매개변수로 넣어 visit를 깊이로 기록