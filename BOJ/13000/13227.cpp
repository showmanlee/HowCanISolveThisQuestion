// TicTacToe
// https://www.acmicpc.net/problem/13227

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<char> board(9);
	for (int i = 0; i < 9; i++) {
		cin >> board[i];
	}
	bool res = false;
	for (int i = 0; i < 3; i++) {
		if ((board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2] && board[i * 3] != '.')
		|| (board[i] == board[3 + i] && board[i] == board[6 + i] && board[i] != '.')
		|| (board[0] == board[4] && board[4] == board[8] && board[0] != '.')
		|| (board[2] == board[4] && board[4] == board[6] && board[2] != '.')) {
			res = true;
			break;
		}
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 주어진 틱택토 보드가 끝난 상태인지 확인하기

// O나 X가 3개 연속으로 이어져있으면 통과 - .이 이어져있으면 안 됨에 주의