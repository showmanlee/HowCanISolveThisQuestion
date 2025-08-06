// 네모네모 시력검사
// https://www.acmicpc.net/problem/18242

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n + 2, vector<char>(m + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	int sx, sy, ex, ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '#') {
				if (board[i + 1][j] == '#' && board[i][j + 1] == '#') {
					sx = i;
					sy = j;
				} 
				if (board[i - 1][j] == '#' && board[i][j - 1] == '#') {
					ex = i;
					ey = j;
				} 
			}
		}
	}
	int cx = (sx + ex) / 2;
	int cy = (sy + ey) / 2;
	string res;
	if (board[cx][sy] != '#') {
		res = "LEFT";
	} else if (board[cx][ey] != '#') {
		res = "RIGHT";
	} else if (board[sx][cy] != '#') {
		res = "UP";
	} else if (board[ex][cy] != '#') {
		res = "DOWN";
	}
	cout << res << '\n';
}

// n*m 보드에 그려진 정사각형에 뚫린 1칸의 방향 구하기