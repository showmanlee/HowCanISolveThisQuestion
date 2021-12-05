// 벽 타기
// https://www.acmicpc.net/problem/23563

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int sx, sy, ex, ey;
	vector<vector<char>> board_t(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board_t[i][j];
			if (board_t[i][j] == 'S') {
				sx = i;
				sy = j;
				board_t[i][j] = '.';
			}
			else if (board_t[i][j] == 'E') {
				ex = i;
				ey = j;
				board_t[i][j] = '.';
			}
		}
	}
	vector<vector<int>> board(n, vector<int>(m, -1));
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (board_t[i][j] == '#') {
				board[i][j] = -1;
			}
			else {
				board[i][j] = 1;
				for (int t = 0; t < 4; t++) {
					int xx = i + dx[t];
					int yy = j + dy[t];
					if (board_t[xx][yy] == '#') {
						board[i][j] = 0;
					}
				}
			}
		}
	}
	vector<vector<int>> dist(n, vector<int>(m, 987654321));
	dist[sx][sy] = 0;
	priority_queue<prr> pq;
	pq.push({ 0, {sx, sy} });
	while (!pq.empty()) {
		int len = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (board_t[xx][yy] == '#') {
				continue;
			}
			int nlen = len;
			if (board[x][y] != 0 || board[xx][yy] != 0) {
				nlen++;
			}
			if (nlen < dist[xx][yy]) {
				dist[xx][yy] = nlen;
				pq.push({ -nlen, {xx, yy} });
			}
		}
	}
	cout << dist[ex][ey] << '\n';
}

// 벽이 있는 n*m 보드에서 벽을 타고 이동할 때 이동 시간이 들지 않을 때, 출발점에서 도착점까지 이동하는데 걸리는 최소 시간은?

// 2차원 다익스트라 문제
// 보드를 받고, 빈칸이 벽에 인접한 칸인지 아닌지를 먼저 판정해둔다
// 이후 출발점부터 다익스트라를 타는데, 인접한 칸끼리 이동하는 경우 거리를 추가하지 않는다