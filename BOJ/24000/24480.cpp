// 알고리즘 수업 - 깊이 우선 탐색 2
// https://www.acmicpc.net/problem/24480

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<vector<int>> board;
int visit[100001];
int cnt;

void dfs(int p) {
	visit[p] = ++cnt;
	for (int i : board[p]) {
		if (visit[i] == 0) {
			dfs(i);
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
		sort(board[i].begin(), board[i].end(), greater<int>());
	}
	cnt = 0;
	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << visit[i] << '\n';
	}
}

// 그래프를 깊이 우선 탐색할 때 각 노드의 탐색 순서 출력하기

// 노드를 오름차순으로 2차원 vector의 각 vector를 역으로 정렬해두기
// 그 외에는 일반적인 DFS 기본 문제라고 볼 수 있을 듯 - visit를 방문 순서로