// 알고리즘 수업 - 너비 우선 탐색 2
// https://www.acmicpc.net/problem/24445

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
	vector<int> visit(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(board[i].begin(), board[i].end(), greater<int>());
	}
	queue<int> q;
	q.push(r);
	visit[r] = 1;
	int order = 2;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i : board[p]) {
			if (visit[i] == 0) {
				visit[i] = order;
				order++;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << visit[i] << '\n';
	}
}

// 그래프를 너비 우선 탐색할 때 각 노드의 탐색 순서 출력하기

// 노드를 내림차순으로 방문해야 하기 때문에 2차원 vector를 내림차순으로 정렬
// 그 외에는 1번 문제와 동일함
// 확실히 set을 쓰는 것보다 마지막에 정렬시키는 게 더 빠르긴 하네