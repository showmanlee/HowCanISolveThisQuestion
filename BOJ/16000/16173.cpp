// 점프왕 쩰리 (Small)
// https://www.acmicpc.net/problem/16173

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	vector<vector<bool>> visit(n, vector<bool>(n));
	queue<pr> q;
	q.push({0, 0});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (board[x][y] == -1) {
			break;
		}
		if (x + board[x][y] < n && !visit[x + board[x][y]][y]) {
			visit[x + board[x][y]][y] = true;
			q.push({x + board[x][y], y});
		}
		if (y + board[x][y] < n && !visit[x][y + board[x][y]]) {
			visit[x][y + board[x][y]] = true;
			q.push({x, y + board[x][y]});
		}
	}
	cout << (visit[n - 1][n - 1] ? "HaruHaru" : "Hing") << '\n';
}

// n*n 보드에서 좌측 상단에서 우측 하단까지 칸에 적혀진 숫자만큼 하단 또는 우측으로 이동하여 움직일 때, 우측 하단까지 도달할 수 있는지 판정하기

// 일반적인 bfs 문제 - 보드를 벗어나면 안 되고, 칸에 0이 적혀있을 수도 있음