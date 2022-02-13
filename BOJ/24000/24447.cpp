// 알고리즘 수업 - 너비 우선 탐색 4
// https://www.acmicpc.net/problem/24447

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
	vector<long long> visit(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(board[i].begin(), board[i].end());
	}
	queue<int> q;
	q.push(r);
	visit[r] = 0;
	long long order = 2;
	long long res = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i : board[p]) {
			if (visit[i] == -1) {
				visit[i] = visit[p] + 1;
				res += order * visit[i];
				order++;
				q.push(i);
			}
		}
	}
	cout << res << '\n';
}

// 그래프를 너비 우선 탐색하여 방문 단계별로 트리를 만들 때, 출발 노드(루트)부터 시작한 각 노드의 depth 출력하기

// 1번 문제와 3번 문제의 복합 - 오름차순 방문 순서 * 깊이
// 노드 수가 10만 개이므로 일렬로 놓인 그래프에 대응하기 위해 long long으로 계산