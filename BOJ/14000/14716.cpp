// 현수막
// https://www.acmicpc.net/problem/14716

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && board[i][j] == 1) {
				queue<pr> q;
				q.push({ i, j });
				visit[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 8; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy] || board[xx][yy] == 0)
							continue;
						visit[xx][yy] = true;
						q.push({ xx ,yy });
					}
				}
				res++;
			}
		}
	}
	cout << res << '\n';
}

// n*m 보드에서 상하좌우대각선으로 1이 이어져있을 때 한 글자라고 할 때, 몇 글자가 있는가?
// 흔한 bfs로 영역 갯수 구하는 문제 - 그런데 이제 영역이 대각선으로도 이어지는
// dx/dy를 대각선에 대응하도록 확장하면 ok