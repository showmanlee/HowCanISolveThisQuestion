// 오목
// https://www.acmicpc.net/problem/2615

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> board(21, vector<int>(21));
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0;
	int x = 0, y = 0;
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 15; j++) {
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i][j + 4] && board[i][j] != 0) {
				if (board[i][j - 1] == board[i][j] || board[i][j + 5] == board[i][j]) {
					continue;
				}
				res = board[i][j];
				x = i;
				y = j;
				break;
			}
		}
		if (res != 0) {
			break;
		}
	}
	if (res == 0) {
		for (int i = 1; i <= 15; i++) {
			for (int j = 1; j <= 19; j++) {
				if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i + 3][j] == board[i + 4][j] && board[i][j] != 0) {
					if (board[i - 1][j] == board[i][j] || board[i + 5][j] == board[i][j]) {
						continue;
					}
					res = board[i][j];
					x = i;
					y = j;
					break;
				}
			}
			if (res != 0) {
				break;
			}
		}
	}
	if (res == 0) {
		for (int i = 1; i <= 15; i++) {
			for (int j = 1; j <= 15; j++) {
				if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 4] && board[i][j] != 0) {
					if (board[i - 1][j - 1] == board[i][j] || board[i + 5][j + 5] == board[i][j]) {
						continue;
					}
					res = board[i][j];
					x = i;
					y = j;
					break;
				}
				if (board[i][j + 4] == board[i + 1][j + 3] && board[i + 1][j + 3] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 1] && board[i + 3][j + 1] == board[i + 4][j] && board[i][j + 4] != 0) {
					if (board[i - 1][j + 5] == board[i][j + 4] || board[i + 5][j - 1] == board[i][j + 4]) {
						continue;
					}
					res = board[i][j + 4];
					x = i + 4;
					y = j;
					break;
				}
			}
			if (res != 0) {
				break;
			}
		}
	}
	cout << res << '\n';
	if (res != 0) {
		cout << x << ' ' << y << '\n';
	}
}

// 주어진 바둑판에서 오목 승리 여부 판정하기

// 둘이 동시에 이기는 경우는 없음 - 하지만 육목 이상이 나오면 승리가 아님
// 따라서 정확히 5개가 일직선이 되는지 확인해야 함 - 확인하는 건 브포로 할 수 있음
// 위의 경우 + 좌측 상단 좌표 표기에 주의할 것