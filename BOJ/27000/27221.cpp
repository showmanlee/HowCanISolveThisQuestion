// 도넛 행성
// https://www.acmicpc.net/problem/27211

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
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && !visit[i][j]) {
				res++;
				visit[i][j] = true;
				queue<pr> q;
				q.push({i, j});
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0) {
							xx = n - 1;
						} else if (xx >= n) {
							xx = 0;
						}
						if (yy < 0) {
							yy = m - 1;
						} else if (yy >= m) {
							yy = 0;
						}
						if (!visit[xx][yy] && board[xx][yy] == 0) {
							visit[xx][yy] = true;
							q.push({xx, yy});
						}
					}
				}
			}
		}
	}
	cout << res << '\n';
}

// x축/y축의 끝단이 서로 이어지는 2차원 공간에서 독립된 0 영역 개수 구하기