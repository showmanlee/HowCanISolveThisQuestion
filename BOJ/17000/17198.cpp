// Bucket Brigade
// https://www.acmicpc.net/problem/17198

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<vector<char>> board(10, vector<char>(10));
	int sx, sy, ex, ey;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'B') {
				sx = i;
				sy = j;
			} else if (board[i][j] == 'L') {
				ex = i;
				ey = j;
			}
		}
	}
	vector<vector<int>> visit(10, vector<int>(10, -1));
	queue<pr> q;
	q.push({sx, sy});
	visit[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == ex && y == ey) {
			cout << (visit[x][y] - 1) << '\n';
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= 10 || yy >= 10 || board[xx][yy] == 'R') {
				continue;
			}
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				q.push({xx, yy});
			}
		}
	}
}

// 10x10 보드에서 R을 밟지 않고 B부터 L까지 도달하는 최단 거리 출력하기

// 기본적인 bfs 문제 