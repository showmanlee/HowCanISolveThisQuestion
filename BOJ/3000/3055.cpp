// 탈출
// https://www.acmicpc.net/problem/3055

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

	int r, c;
	cin >> r >> c;
	vector<vector<char>> board(r, vector<char>(c));
	vector<vector<int>> water(r, vector<int>(c, 987654321));
	vector<vector<bool>> visit(r, vector<bool>(c));
	queue<prr> q;
	int sx, sy, gx, gy;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == '*') {
				water[i][j] = 0;
				q.push({ {i, j}, 0 });
			}
			else if (board[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (board[i][j] == 'D') {
				gx = i;
				gy = j;
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
			if (xx < 0 || yy < 0 || xx >= r || yy >= c || board[xx][yy] == 'X' || board[xx][yy] == 'D')
				continue;
			if (water[xx][yy] == 987654321) {
				water[xx][yy] = time + 1;
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
		if (x == gx && y == gy) {
			res = time;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= r || yy >= c || board[xx][yy] == 'X' || visit[xx][yy])
				continue;
			if (water[xx][yy] > time + 1) {
				visit[xx][yy] = true;
				q.push({ {xx, yy}, time + 1 });
			}
		}
	}
	if (res == -1)
		cout << "KAKTUS\n";
	else
		cout << res << '\n';
}

// 매 초마다 물이 번지는 숲에서 고슴도치는 굴로 피신할 수 있는가? 있다면 최소 시간은 얼마나 걸리는가?
// 최소 시간을 구하라고 했으니 당연히 bfs로 접근
// 물이 퍼지는 것과 내가 이동하는 것은 독립인자 - 물이 퍼지는 시간을 따로 기록한 후, 그 시간에 겹치지 않도록 내가 이동하는 것을 구현
// 만약 그 칸에 도달하는 시간이 물이 도달하는 시간보다 빠른 경우 그 칸에 이동 가능, 그렇지 않으면 불가능
// 이를 이용해 나아가다가 도착점에 도달하면 결과 갱신 후 탈출하기
// 물이 반드시 있다는 것을 보장하지 않기 때문에 뮬이 퍼지는 시간의 기본값을 매우 큰 값으로 맞출 필요가 있음 - 물이 없으면 물이 퍼지는 시간 갱신 불가능
// 여기서 일정 지점이 아닌 맵 바깥으로 가는 것이 목적인 게 5427 불