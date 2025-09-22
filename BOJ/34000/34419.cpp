// Tic-Tac-Toe Solver
// https://www.acmicpc.net/problem/34419

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<char>> board(3, vector<char>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[i][j];
		}
	}
	char res = 'N';
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != 'E') {
			res = board[i][0];
			break;
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != 'E') {
			res = board[0][i];
			break;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != 'E') {
		res = board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != 'E') {
		res = board[0][2];
	}
	cout << res << '\n';
}

// n의 약수가 아닌 가장 작은 자연수와 가장 큰 자연수 구하기