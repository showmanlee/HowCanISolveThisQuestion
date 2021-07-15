// 주사위 굴리기
// https://www.acmicpc.net/problem/14499

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int dice[7] = { 0, 0, 0, 0, 0, 0, 0 };
int n, m, x, y, k;

bool rotate(int d) {
	x += dx[d];
	y += dy[d];
	if (x < 0 || y < 0 || x >= n || y >= m) {
		x -= dx[d];
		y -= dy[d];
		return false;
	}
	if (d == 1) {
		int temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = temp;
	}
	else if (d == 2) {
		int temp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = temp;
	}
	else if (d == 3) {
		int temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = temp;
	}
	else if (d == 4) {
		int temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = temp;
	}
	return true;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> x >> y >> k;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	for (int i = 0; i < k; i++) {
		int d;
		cin >> d;
		if (rotate(d)) {
			if (board[x][y] == 0) 
				board[x][y] = dice[6];
			else {
				dice[6] = board[x][y];
				board[x][y] = 0;
			}
			cout << dice[1] << '\n';
		}
	}
}

// 숫자가 적힌 n*m 보드에서 0으로 채워진 주사위를 굴려서 주사위 밑면이 바닥과 만나면 해당 바닥에 적힌 수를 가져오거나 복사해줄 때, 주사위를 굴릴 수 있는 상황에서 굴려서 나온 윗면 출력하기

// 우선 문제에서 주어진 인덱스를 가진 주사위 배열을 생성하고, 보드와 위치 입력 받기
// 주사위의 경우 위치값과 각 면에 적힌 숫자를 저장 - 위치값은 이동이 가능한지 판정하는데도 사용
// 이후 움직이는 방향을 받아 주사위를 굴린다 - 각 면의 인덱스는 해당 방향을 고정적으로 가리키고, 인덱스의 값을 교환해주면서 굴리는 것으로 처리(1은 앞, 6은 뒤)
// 만약 굴릴 수 있는 상황(굴려도 벗어나지 않는 상황)이었다면 실제로 주사위를 굴린 후, 바닥면(6)과 보드의 값을 보고 보드의 값을 바닥면에 복사할지, 반대로 할지 결정
// 이후 윗면(1) 출력하기