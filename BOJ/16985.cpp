// Maaaaaaaaaze
// https://www.acmicpc.net/problem/16985

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct coord {
	int x, y, z;
	coord() : x(0), y(0), z(0) {}
	coord(int a, int b, int c) : x(a), y(b), z(c) {}
};

int input[5][5][5][4];
int board[5][5][5];

int main(void) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> input[i][j][k][0];
		for (int r = 1; r < 4; r++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					input[i][j][k][r] = input[i][k][4 - j][r - 1];
	}
	vector<int> select(5);
	for (int i = 0; i < 5; i++)
		select[i] = i;
	int res = 987654321;
	do {
		for (int t = 0; t < 1024; t++) {
			int rotation[5] = { t % 4, t / 4 % 4, t / 16 % 4, t / 64 % 4, t / 256 % 4 };
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						board[i][j][k] = input[select[i]][j][k][rotation[i]];
			vector<vector<vector<int>>> visit(5, vector<vector<int>>(5, vector<int>(5, -1)));
			if (board[0][0][0] == 0 || board[4][4][4] == 0)
				continue;
			queue<coord> q;
			q.push(coord(0, 0, 0));
			visit[0][0][0] = 0;
			while (!q.empty()) {
				coord c = q.front();
				int cur = visit[c.x][c.y][c.z];
				q.pop();
				for (int i = 0; i < 6; i++) {
					int xx = c.x + dx[i];
					int yy = c.y + dy[i];
					int zz = c.z + dz[i];
					if (xx < 0 || yy < 0 || zz < 0 || xx > 4 || yy > 4 || zz > 4)
						continue;
					if (board[xx][yy][zz] == 1 && visit[xx][yy][zz] == -1) {
						visit[xx][yy][zz] = cur + 1;
						q.push(coord(xx, yy, zz));
					}
				}
			}
			if (visit[4][4][4] != -1)
				res = min(res, visit[4][4][4]);
		}
	} while (next_permutation(select.begin(), select.end()));
	if (res == 987654321)
		res = -1;
	cout << res << '\n';
}

// 5개의 5*5 보드를 회전하고 쌓아 3차원 배열을 만들 때, [0][0][0]에서 [4][4][4]까지 도달하는 거리가 최소인 경우의 길이는?
// 보드의 위치와 회전 상황을 고려해야 하는 브루트포스 - 경우의 수는 (5! * 4^5) = 122880
// 보드의 회전 형태를 미리 input 배열에 저장해두고 경우에 따라 뽑아쓸 수 있게 설정
// - 시계방향 회전 공식 = [x][y] = [y][n - 1 - x]
// 보드 선택은 next_permutation과 4^5 순회 선택, 이후 3차원 BFS를 돌려 도달 여부 확인하기
// [0][0][0] 또는 [4][4][4]가 막혀 있는 경우 패스 - 두 곳이 뚫려있더라도 중간이 막혀있는 경우도 있기에 res 갱신 전에 도달 여부 확인하기
// 거리 측정은 visit 배열에 거리를 저장하도록 운영