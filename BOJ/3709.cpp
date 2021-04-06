// 레이저빔은 어디로
// https://www.acmicpc.net/problem/3709

#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, r;
		cin >> n >> r;
		vector<vector<bool>> board(n + 1, vector<bool>(n + 1));
		for (int i = 0; i < r; i++) {
			int a, b;
			cin >> a >> b;
			board[a][b] = true;
		}
		int sx, sy;
		cin >> sx >> sy;
		int dir = 0;
		if (sx == n + 1) 
			dir = 0;
		else if (sy == 0) 
			dir = 1;
		else if (sx == 0) 
			dir = 2;
		else if (sy == n + 1) 
			dir = 3;
		vector<vector<vector<bool>>> visit(n + 1, vector<vector<bool>>(n + 1, vector<bool>(4)));
		int x = sx, y = sy;
		int gx = 0, gy = 0;
		while (true) {
			x += dx[dir];
			y += dy[dir];
			if (x <= 0 || y <= 0 || x > n || y > n) {
				gx = x;
				gy = y;
				break;
			}
			if (board[x][y])
				dir = (dir + 1) % 4;
			if (!visit[x][y][dir])
				visit[x][y][dir] = true;
			else
				break;
		}
		cout << gx << ' ' << gy << '\n';
	}
}

// n*n 보드 변 중 하나에 레이저 포인터가 있고, 보드 안에는 레이저 방향을 우측으로 90도 꺾는 거울이 있을 때, 레이저가 탈출할 수 있는가? 탈출할 수 있다면 탈출하는 좌표는?
// bfs지만 진행방향이 하나밖에 없어서 굳이 큐를 만들지 않아도 됨 - while(true) 안에서 해결
// 레이저 포인터 위치를 이용해 레이저 방향을 잡고, 해당 방향으로 이동 후 탈출에 성공했다면 성공 판정하기
// 루프 판정을 위해 visit 배열은 3차원으로 준비 - x, y, dir
// 만약 해당 위치에서 같은 방향으로 레이저가 뻗은 적이 있다면 그 이후로도 계속 갔던 곳/방향으로 돌게 될 것
// 문제 설명에 '행'과 '열'이 반대로 주어져 있음에 주의 - 일반적인 2차원 보드 좌표계로 풀면 됨