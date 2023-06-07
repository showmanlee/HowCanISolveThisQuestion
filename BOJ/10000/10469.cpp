// 사이 나쁜 여왕들
// https://www.acmicpc.net/problem/10469

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<vector<char>> board(8, vector<char>(8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	bool res = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == '*') {
				cnt++;
				for (int t = 0; t < 8; t++) {
					int x = i, y = j;
					while (true) {
						x += dx[t];
						y += dy[t];
						if (x < 0 || y < 0 || x >= 8 || y >= 8) {
							break;
						}
						if (board[x][y] == '*') {
							res = false;
							break;
						}
					}
					if (!res) {
						break;
					}
				}
			}
			if (!res) {
				break;
			}
		}
		if (!res) {
			break;
		}
	}
	if (res && cnt != 8) {
		res = false;
	}
	cout << (res ? "valid" : "invalid") << "\n";
 }

// 8*8 체스판에 8개의 퀸이 놓여 있을 때, 퀸들이 서로를 잡을 수 없는지 판정하기

// 보드를 돌면서 직접 판정해주면 되긴 합니다
// 보드에서 퀸 8개가 놓여 있다는 보장이 없음 - 따라서 개수 체크까지 해줘야 한다
