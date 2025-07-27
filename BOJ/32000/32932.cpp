// 드론 조작
// https://www.acmicpc.net/problem/32932

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<bool>> board(1001, vector<bool>(1001));
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		board[a + 500][b + 500] = true;
	}
	int x = 500, y = 500;
	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		if (c == 'L') {
			x--;
			if (board[x][y]) {
				x++;
			}
		}
		if (c == 'R') {
			x++;
			if (board[x][y]) {
				x--;
			}
		}
		if (c == 'U') {
			y++;
			if (board[x][y]) {
				y--;
			}
		}
		if (c == 'D') {
			y--;
			if (board[x][y]) {
				y++;
			}
		}
	}
	x -= 500;
	y -= 500;
	cout << x << ' ' << y << '\n';
}

// -500~500의 2차원 보드에서 특정 좌표들에 장애물이 있을 때, 원점에서 주어진 대로 이동한 결과 출력하기