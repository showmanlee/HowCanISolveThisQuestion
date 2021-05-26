// 다오의 데이트
// https://www.acmicpc.net/problem/18188

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, string> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;
	vector<vector<char>> board(h, vector<char>(w));
	int sx, sy, gx, gy;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'D') {
				sx = i;
				sy = j;
				board[i][j] = '.';
			}
			if (board[i][j] == 'Z') {
				gx = i;
				gy = j;
				board[i][j] = '.';
			}
		}
	}
	int n;
	cin >> n;
	vector<vector<bool>> dir(n, vector<bool>(4));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			char c;
			cin >> c;
			if (c == 'W')
				dir[i][0] = true;
			if (c == 'A')
				dir[i][1] = true;
			if (c == 'S')
				dir[i][2] = true;
			if (c == 'D')
				dir[i][3] = true;
 		}
	}
	vector<vector<int>> visit(h, vector<int>(w, -1));
	visit[sx][sy] = 0;
	queue<prr> q;
	q.push({ {sx, sy}, "" });
	string res = "";
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		string path = q.front().second;
		q.pop();
		if (x == gx && y == gy) {
			res = path;
			break;
		}
		if (visit[x][y] >= n)
			continue;
		int turn = visit[x][y];
		for (int i = 0; i < 4; i++) {
			if (!dir[turn][i])
				continue;
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= h || yy >= w)
				continue;
			if (board[xx][yy] == '.') {
				visit[xx][yy] = visit[x][y] + 1;
				string npath = path;
				if (i == 0)
					npath += 'W';
				if (i == 1)
					npath += 'A';
				if (i == 2)
					npath += 'S';
				if (i == 3)
					npath += 'D';
				q.push({ {xx, yy}, npath });
			}
		}
	}
	if (res == "")
		cout << "NO\n";
	else
		cout << "YES\n" << res << '\n';
}

// 다오가 디지니를 만나기 위해 h*w 공간을 움직이는데, 각 턴에 마리드가 정한 두 방향으로만 움직일 수 있을 때 다오가 n턴만에 디지니를 만날 수 있는가? 있다면 어떻게 가야 하는가?

// 각 턴마다 이동 방향이 한정되어 있는 bfs - 최단 거리를 물어보는 것은 아니라 최단 거리 이상으로 가도 결과로 인정
// 따라서 큐를 돌리면서 현재까지 들렀던 경로를 함께 기록하며 움직이다가, 목적지에 도달하면 해당 경로 출력 - n턴을 넘어선다면 추가 탐색 X
// 이동 방향 판정은 2차원 bool 배열 형태로 처리하여, 해당 턴에 해당 방향(dx, dy)로 움직일 수 있는지 표시하도록 함
// 여기서는 이미 방문한 칸이라도 이동해야 함에 주의 - 이동 방향 한정에 의해 밟은 길을 다시 밟아야 도착할 수 있는 경로도 있음(예제 5)