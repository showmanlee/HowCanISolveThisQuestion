// Sudoku Verify
// https://www.acmicpc.net/problem/34444

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> board(9, vector<int>(9));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
	bool pass = true;
	for (int i = 0; i < 9; i++) {
		int a = 0;
		int b = 0;
		for (int j = 0; j < 9; j++) {
			a |= (1 << board[i][j]);
			b |= (1 << board[j][i]);
		}
		if (a != 1022 || b != 1022) {
			pass = false;
			break;
		}
	}
	if (pass) {
		for (int x = 0; x < 9; x += 3) {
			for (int y = 0; y < 9; y += 3) {
				int c = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						c |= (1 << board[x + i][y + j]);
					}
				}
				if (c != 1022) {
					pass = false;
					goto failed;
				}
			}
		}
	}
	failed:
	cout << (pass ? "VALID" : "INVALID!") << '\n';
}

// 스도쿠 보드가 맞는지 확인하기