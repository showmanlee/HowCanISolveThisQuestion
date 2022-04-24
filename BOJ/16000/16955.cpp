// 오목, 이길 수 있을까?
// https://www.acmicpc.net/problem/16955

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<char>> board(10, vector<char>(10));
	vector<pr> candi;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'X') {
				candi.push_back({ i, j });
			}
		}
	}
	int res = 0;
	for (pr p : candi) {
		int x = p.first;
		int y = p.second;
		for (int t = 0; t < 8; t++) {
			int xt = x + dx[t] * 4;
			int yt = y + dy[t] * 4;
			if (xt < 0 || yt < 0 || xt >= 10 || yt >= 10) {
				continue;
			}
			int cnt = 0;
			for (int i = 0; i < 5; i++) {
				int xx = x + dx[t] * i;
				int yy = y + dy[t] * i;
				if (board[xx][yy] == 'O') {
					cnt = 999;
					break;
				}
				else if (board[xx][yy] == '.') {
					cnt++;
				}
			}
			if (cnt == 1) {
				res = 1;
				break;
			}
		}
		if (res) {
			break;
		}
	}
	cout << res << '\n';
}

// 10x10 보드에서 오목을 둘 때, X가 돌을 하나 놓아 이길 수 있는가?

// 보드를 받으며 X가 있는 칸을 모두 모아둔다
// 이후 X에 대해 8방향으로 탐색하면서 O가 등장하지 않으면서 .가 1번만 존재하는 경우가 있으면 성공, 아니면 실패