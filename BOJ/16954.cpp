// 움직이는 미로 탈출
// https://www.acmicpc.net/problem/16954

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<vector<char>>> board(8, vector<vector<char>>(8, vector<char>(8)));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> board[0][i][j];
	for (int t = 1; t < 8; t++) {
		for (int j = 0; j < 8; j++)
			board[t][0][j] = '.';
		for (int i = 1; i < 8; i++)
			for (int j = 0; j < 8; j++)
				board[t][i][j] = board[t - 1][i - 1][j];
	}
	vector<vector<int>> visit(8, vector<int>(8, -1));
	queue<prr> q;
	q.push({ 0, {7, 0} });
	visit[7][0] = 0;
	int res = 0;
	while (!q.empty()) {
		int t = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (t >= 8 || (x == 0 && y == 7)) {
			res = 1;
			break;
		}
		for (int i = 0; i < 9; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx > 7 || yy > 7)
				continue;
			if (visit[xx][yy] != -1 && (xx != x || yy != y))
				continue;
			if (t < 7 && board[t + 1][xx][yy] == '#')
				continue;
			if (board[t][xx][yy] != '#') {
				visit[xx][yy] = t + 1;
				q.push({ t + 1, {xx, yy} });
			}
		}
	}
	cout << res << '\n';
}

// 8*8 보드에서 벽들이 아래로 한 칸씩 내려올 때, 벽에 부딪히지 않고 좌측 하단에서 우측 상단으로 이동할 수 있는가?

// 벽들은 한 번 이동한 이후 한 칸씩 내려오고, 맨 아래의 벽들은 사라진다
// 이 원리를 이용해 0~7 시점에서의 보드를 새로 그려주기 - 8 이상의 시점에서는 모든 칸이 빈칸이 되므로 무조건 통과 가능
// 또한 여기서는 상하좌우는 물론 대각선 이동, 심지어 멈춰있는 것도 가능
// 따라서 visit를 운영할 때 멈추는 경우 visit 판정을 하지 않게 하기 - 기다렸다가 움직여야 하는 경우도 있음
// 그리고 시간이 8 이상이 되었을 때까지 살았다면 더 볼 것 없이 이동할 수 있기에 바로 성공 판정하기
// 이 점들을 기억하고 bfs를 돌리면 됨 - 현재 또는 다음 시점에서 벽이 위치하는 경우 이동하지 않도록