// 직사각형 탈출
// https://www.acmicpc.net/problem/16973

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	int h, w, sr, sc, fr, fc;
	cin >> h >> w >> sr >> sc >> fr >> fc;
	vector<vector<int>> visit(n + 1, vector<int>(m + 1, -1));
	queue<pr> q;
	q.push({ sr, sc });
	visit[sr][sc] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == fr && y == fc) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx <= 0 || yy <= 0 || xx + h - 1 > n || yy + w - 1 > m || visit[xx][yy] != -1) {
				continue;
			}
			bool pass = false;
			if (i == 0) {
				for (int j = yy; j < yy + w; j++) {
					if (board[xx][j] == 1) {
						pass = true;
					}
				}
			}
			else if (i == 1) {
				for (int j = xx; j < xx + h; j++) {
					if (board[j][yy + w - 1] == 1) {
						pass = true;
					}
				}
			}
			else if (i == 2) {
				for (int j = yy; j < yy + w; j++) {
					if (board[xx + h - 1][j] == 1) {
						pass = true;
					}
				}
			}
			else if (i == 3) {
				for (int j = xx; j < xx + h; j++) {
					if (board[j][yy] == 1) {
						pass = true;
					}
				}
			}
			if (pass) {
				continue;
			}
			visit[xx][yy] = visit[x][y] + 1;
			q.push({ xx, yy });
		}
	}
	cout << visit[fr][fc] << '\n';
}

// n*m 보드에서 h*w 직사각형을 장애물과 겹치거나 보드에서 벗어나지 않고 출발점에서 도착점으로 이동하는데 걸리는 최소 시간은?

// 이동하는 말의 크기가 1*1이 아닌 bfs
// 이 경우 맵 탈출 여부는 끝점 좌표(xx + h - 1, yy + w - 1)이 벗어났는지 보고, 장애물 침범 여부는 h*w 범위에 장애물이 있는지 보면 된다
// 다만 장애물 침범 여부 판별을 위해 h*w를 모두 돌게 되면 시간 초과 발생
// 따라서 이동한 방향을 보고, 이동으로 인해 새로 밟게된 칸들(1*?)만 장애물 침범 여부를 판정해야 한다
