// 아기돼지와 늑대
// https://www.acmicpc.net/problem/16441

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
	vector<vector<char>> board(n, vector<char>(m));
	vector<pr> wolves;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'W') {
				wolves.push_back({ i, j });
				board[i][j] = '.';
			}
		}
	}
	vector<vector<bool>> visit(n, vector<bool>(m));
	queue<pr> q;
	for (pr w : wolves) {
		if (visit[w.first][w.second])
			continue;
		visit[w.first][w.second] = true;
		q.push(w);
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (board[xx][yy] == '#')
					continue;
				if (board[xx][yy] == '+') {
					while (board[xx][yy] == '+') {
						xx += dx[i];
						yy += dy[i];
					}
					if (board[xx][yy] == '#') {
						xx -= dx[i];
						yy -= dy[i];
					}
				}
				if (!visit[xx][yy]) {
					visit[xx][yy] = true;
					q.push({ xx, yy });
				}
			}
		}
	}
	for (pr w : wolves)
		board[w.first][w.second] = 'W';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && board[i][j] == '.')
				board[i][j] = 'P';
			cout << board[i][j];
		}
		cout << '\n';
	}
}

// 산과 초원, 빙판으로 구성된 n*m 지형에서 늑대들은 원래 위치에서 산을 제외한 지형을 상하좌우로 이동할 수 있고, 빙판을 밟으면 산에 부딪히거나 초원에 올라갈 때까지 그 방향으로 미끄러진다
// 이 때, 아기돼지가 늑대의 침입 걱정 없이 집을 지을 수 있는 초원의 위치는?

// bfs 범위탐색 - 빙판을 밟았을 때 미끄러지는 것을 판정해야 하는
// 우선 보드를 받으면서 늑대의 위치일 경우 별도의 배열에 위치를 빼고 해당 위치를 초원으로 표시
// 이후 늑대 위치들을 순회하면서 bfs 돌입 - 이전 늑대에 의해 해당 위치가 탐색되었을 때는 생략
// 일반적인 방법으로 bfs를 돌리되, 만약 빙판을 밟은 경우 빙판이 아닐 때까지 해당 방향으로 계속 이동 - 멈춘 곳이 산인 경우 역방향으로 한 칸 이동
// 테두리가 모두 산임이 보장되기 때문에, 별도의 보드 이탈 판정을 할 필요는 없음
// 이렇게 bfs를 돌리며 얻은 visit 배열이 늑대의 활동범위 - 그리고 초원이면서 !visit인 경우가 집을 지을 수 있는 곳
// 따라서 마지막에 보드를 출력할 때 늑대 위치 배열을 돌며 늑대 위치를 복구한 후, 집을 지을 수 있는 곳이면 해당 위치를 P로 바꾸어 출력