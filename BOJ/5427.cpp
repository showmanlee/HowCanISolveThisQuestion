// 불
// https://www.acmicpc.net/problem/5427

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<pair<int, int>, int> prr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		int w, h;
		cin >> w >> h;
		vector<vector<char>> board(h, vector<char>(w));
		vector<vector<int>> fire(h, vector<int>(w, 987654321));
		vector<vector<bool>> visit(h, vector<bool>(w));
		queue<prr> q;
		int sx, sy;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				if (board[i][j] == '*') {
					fire[i][j] = 0;
					q.push({ {i, j}, 0 });
				}
				else if (board[i][j] == '@') {
					sx = i;
					sy = j;
				}
			}
		}
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int time = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= h || yy >= w || board[xx][yy] == '#')
					continue;
				if (fire[xx][yy] == 987654321) {
					fire[xx][yy] = time + 1;
					q.push({ {xx, yy}, time + 1 });
				}
			}
		}
		q.push({ {sx, sy}, 0 });
		visit[sx][sy] = true;
		int res = -1;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int time = q.front().second;
			q.pop();
			bool exit = false;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= h || yy >= w) {
					exit = true;
					break;
				}
				if (board[xx][yy] != '#' && !visit[xx][yy]) {
					if (fire[xx][yy] > time + 1) {
						visit[xx][yy] = true;
						q.push({ {xx, yy}, time + 1 });
					}
				}
			}
			if (exit) {
				res = time + 1;
				break;
			}
		}
		if (res == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << res << '\n';
	}
}

// 매 초마다 불이 번지는 건물에서 탈출할 수 있는가? 있다면 탈출하는 최소 시간이 얼마인가?
// 최소 시간을 구하라고 했으니 당연히 bfs로 접근
// 불이 퍼지는 것과 내가 이동하는 것은 독립인자 - 불이 퍼지는 시간을 따로 기록한 후, 그 시간에 겹치지 않도록 내가 이동하는 것을 구현
// 만약 그 칸에 도달하는 시간이 불이 도달하는 시간보다 빠른 경우 그 칸에 이동 가능, 그렇지 않으면 불가능
// 이를 이용해 나아가다가 보드 바깥으로 나갈 수 있게 되면 결과 갱신 후 탈출하기
// 불이 반드시 있다는 것을 보장하지 않기 때문에 불이 퍼지는 시간의 기본값을 매우 큰 값으로 맞출 필요가 있음 - 불이 없으면 불이 퍼지는 시간 갱신 불가능