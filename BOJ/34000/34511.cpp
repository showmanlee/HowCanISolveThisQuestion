// Polyominonal Puzzle
// https://www.acmicpc.net/problem/34511

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != '.' && board[i + 1][j] != '.' && board[i][j] != board[i + 1][j]) {
				res++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (board[i][j] != '.' && board[i][j + 1] != '.' && board[i][j] != board[i][j + 1]) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 세 수를 최대 1번씩만 사용해서 더하고 빼서 0을 만들 수 있는지 구하기