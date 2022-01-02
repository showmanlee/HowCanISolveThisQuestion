// 색종이 만들기
// https://www.acmicpc.net/problem/2630

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int zero = 0;
int one = 0;

void dq(vector<vector<char>>& board, int x, int y, int size) {
	if (size == 0)
		return;
	bool same = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++)
			if (board[i][j] != board[x][y])
				same = false;
		if (!same)
			break;
	}
	if (same) {
		if (board[x][y] == '0')
			zero++;
		else
			one++;
	}
	else {
		int p = size / 2;
		dq(board, x, y, p);
		dq(board, x + p, y, p);
		dq(board, x, y + p, p);
		dq(board, x + p, y + p, p);
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}
	dq(board, 0, 0, n);
	cout << zero << "\n" << one << "\n";
}

// 두 가지 색깔 영역 개수 구하기
// 역시 분할정복