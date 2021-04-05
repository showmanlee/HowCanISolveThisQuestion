// 불!
// https://www.acmicpc.net/problem/4179

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<int>> fire(n, vector<int>(m, 987654321));
	vector<vector<int>> run(n, vector<int>(m, -1));
	queue<pr> q;
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') {
				sx = i;
				sy = j;
			}
			else if (board[i][j] == 'F') {
				fire[i][j] = 0;
				q.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == '#')
				continue;
			if (fire[xx][yy] > fire[x][y] + 1) {
				fire[xx][yy] = fire[x][y] + 1;
				q.push({ xx,yy });
			}
		}
	}
	q.push({ sx, sy });
	run[sx][sy] = 0;
	int res = -1;
	while (!q.empty()) {
		bool flag = false;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
				flag = true;
				break;
			}
			if (board[xx][yy] == '#')
				continue;
			if (run[xx][yy] == -1) {
				run[xx][yy] = run[x][y] + 1;
				if (run[xx][yy] < fire[xx][yy])
					q.push({ xx, yy });
			}
		}
		if (flag) {
			res = run[x][y] + 1;
			break;
		}
	}
	if (res == -1)
		cout << "IMPOSSIBLE\n";
	else
		cout << res << '\n';
}

// 불이 퍼지는 미로에서 탈출할 수 있는가? 있다면 탈출에 필요한 최소 시간은?
// bfs - 먼저 불을 퍼뜨려놓아 불이 도달하는 시간을 기록한 후, 탈출하면서 탈출 여부를 판정한다
// 만약 해당 지점에 도달하는 시점보다 불이 늦게 도착하는 경우 해당 지점에 갈 수 있다
// 이렇게 돌면서 미로 밖으로 나오게 되면 현재 위치 + 1을 결과로 출력