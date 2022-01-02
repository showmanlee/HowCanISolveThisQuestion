// 가스관
// https://www.acmicpc.net/problem/2931

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

string pipe = "|-+1234";
int route[7][4] = {
	{0, 2, -1, -1},
	{1, 3, -1, -1},
	{0, 1, 2, 3},
	{2, 3, -1, -1},
	{0, 3, -1, -1},
	{0, 1, -1, -1},
	{2, 1, -1, -1}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;
	vector<vector<char>> board(r + 1, vector<char>(c + 1));
	int sx = -1, sy = -1;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'M') {
				sx = i;
				sy = j;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		int xx = sx + dx[i];
		int yy = sy + dy[i];
		if (xx > 0 && yy > 0 && xx <= r && yy <= c && pipe.find(board[xx][yy]) != string::npos) {
			sx = xx;
			sy = yy;
			break;
		}
	}
	int bx = -1, by = -1;
	vector<vector<bool>> visit(r + 1, vector<bool>(c + 1));
	queue<pr> q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (board[x][y] == '.') {
			bx = x;
			by = y;
			break;
		}
		else if (board[x][y] == 'M' || board[x][y] == 'Z')
			continue;
		for (int i = 0; i < 4; i++) {
			int nd = route[pipe.find(board[x][y])][i];
			if (nd == -1)
				break;
			int xx = x + dx[nd];
			int yy = y + dy[nd];
			if (xx <= 0 || yy <= 0 || xx > r || yy > c || visit[xx][yy])
				continue;
			visit[xx][yy] = true;
			q.push({ xx, yy });
		}
	}
	char bc = '.';
	vector<bool> checker(4);
	for (int i = 0; i < 4; i++) {
		int xx = bx + dx[i];
		int yy = by + dy[i];
		if (xx <= 0 || yy <= 0 || xx > r || yy > c)
			continue;
		if (pipe.find(board[xx][yy]) != string::npos) {
			int nd = pipe.find(board[xx][yy]);
			if (i == 0 && (nd == 0 || nd == 2 || nd == 3 || nd == 6))
				checker[0] = true;
			else if (i == 1 && (nd == 1 || nd == 2 || nd == 3 || nd == 4))
				checker[1] = true;
			else if (i == 2 && (nd == 0 || nd == 2 || nd == 4 || nd == 5))
				checker[2] = true;
			else if (i == 3 && (nd == 1 || nd == 2 || nd == 5 || nd == 6))
				checker[3] = true;
		}
	}
	if (checker[0] && checker[1] && checker[2] && checker[3])
		bc = '+';
	else if (checker[0]) {
		if (checker[1])
			bc = '3';
		else if (checker[2])
			bc = '|';
		else if (checker[3])
			bc = '2';
	}
	else if (checker[1]) {
		if (checker[2])
			bc = '4';
		else if (checker[3])
			bc = '-';
	}
	else if (checker[2] && checker[3])
		bc = '1';
	cout << bx << ' ' << by << ' ' << bc << '\n';
}

// r*c 보드에 M에서 Z로 가는 가스관이 있다 - 가스관은 |, -, +, 1(┌), 2(└), 3(┘), 4(┐) 등 7가지가 있다
// 이때 가스관 중 하나가 없어졌을 때, 채워야 하는 칸의 위치와 가스관의 종류는?

// 입력 선에서 보장되는 것 - M과 Z는 하나의 가스관과 연결되어 있고(M/Z의 가스관 직결 위치가 주어지고), 불필요한 가스관은 없고, 가스관이 중간에 새는 경로도 없다(+로 인해 갈래가 생겨도 모두 한 줄기임이 보장된다)
// 따라서 이미 놓여있는 가스관을 따라가면 단 하나의 빈 공간을 발견할 수 있고, 해당 위치에서 연결이 필요한 방향으로 가스관을 연결하면 그게 답이 된다

// 우선 보드 입력을 받으면서 M의 위치를 가져오고, 해당 위치에서 뻗은 파이프의 위치를 경로 탐색 시작점으로 잡는다
// 이후 bfs로 파이프를 따라 순회한다 - 해당 파이프에 대응하는 진행 방향을 route 배열에 표시해서 탐색
// 그러다가 빈칸을 만나면 파이프를 채워야 할 곳이므로 저장 후 탈출
// 이후 해당 위치 주변에 있는 파이프 정보를 보고, 연결되어야 하는 파이프라면 방향 배열에 체크한다
// 이렇게 체크한 방향 배열의 상태에 따라 채울 파이프를 결정