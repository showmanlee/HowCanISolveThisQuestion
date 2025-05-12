// 누가 이름 안 적고 나갔어
// https://www.acmicpc.net/problem/33578

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int sx, sy, ex, ey;
	vector<vector<char>> board(n, vector<char>(m));
	vector<pr> pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') {
				sx = i;
				sy = j;
			} else if (board[i][j] == 'S') {
				ex = i;
				ey = j;
			} else if (board[i][j] == 'T') {
				pos.push_back({i, j});
			}
		}
	}
	vector<vector<vector<int>>> visit(n, vector<vector<int>>(m, vector<int>(2, 200000000)));
	for (int t = 0; t < 2; t++) {
		queue<pr> q;
		int ssx = (t == 0 ? sx : ex), ssy = (t == 0 ? sy : ey);
		q.push({ssx, ssy});
		visit[ssx][ssy][t] = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == '#') {
					continue;
				}
				if (visit[xx][yy][t] == 200000000) {
					visit[xx][yy][t] = visit[x][y][t] + 1;
					q.push({xx, yy});
				}
			}
		}
	}
	int res = visit[ex][ey][0] * 2;
	for (pr p : pos) {
		res = min(res, visit[p.first][p.second][0] * 2 + visit[p.first][p.second][1]);
	}
	if (res >= 100000000) {
		res = -1;
	}
	cout << res << '\n';
}

// n*m 보드에서 시작점에서 도착점까지 이동하는데 중간에 선생님을 만나면 칸당 이동 시간이 2초에서 1초로 줄어들 때, 최단 시간 구하기