// 알고리즘 수업 - 깊이 우선 탐색 6
// https://www.acmicpc.net/problem/24484

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<vector<int>> board;
long long visit[100001];
long long order[100001];
int cnt;

void dfs(int p, int d) {
	cnt++;
	order[p] = cnt;
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
		sort(board[i].begin(), board[i].end(), greater<int>());
		visit[i] = -1;
	}
	cnt = 0;
	dfs(r, 0);
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += order[i] * visit[i];
	}
	cout << res << '\n';
}

// 그래프를 깊이 우선 탐색할 때 각 노드의 방문 순서와 깊이의 곱 출력하기

// 노드를 내림차순으로 2차원 vector의 각 vector를 정렬해두기
// 그 외에는 저 문제의 BFS 버전과 동일함