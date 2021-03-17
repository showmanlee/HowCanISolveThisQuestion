// 결혼식
// https://www.acmicpc.net/problem/5567

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	vector<bool> visit(n + 1);
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i : board[p]) {
			if (!visit[i]) {
				visit[i] = true;
				if (p == 1)
					q.push(i);
			}
		}
	}
	int res = 0;
	for (int i = 2; i <= n; i++)
		if (visit[i])
			res++;
	cout << res << '\n';
}

// 1번이 결혼식에 친구와 친구의 친구를 초대하려고 할 때, 초대할 사람 수는?
// 깊이가 2까지인 BFS - 2차원 vector로 그래프 만들고, 방문한 사람들 수를 세서 결과 출력하기
// 시작점이 정해져있고 깊이가 2까지이기 때문에 깊이를 따로 저장할 필요가 없음 - 시작점이 1이 아니라면 큐에 넣지 않고 탐색만 진행