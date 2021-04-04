// 종이의 개수
// https://www.acmicpc.net/problem/1780

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int zero = 0;
int positive = 0;
int negative = 0;

void dq(vector<vector<int>>& board, int x, int y, int size) {
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
		if (board[x][y] == 0)
			zero++;
		else if (board[x][y] == 1)
			positive++;
		else
			negative++;
	}
	else {
		int p = size / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				dq(board, x + p * i, y + p * j, p);
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}
	dq(board, 0, 0, n);
	cout << negative << "\n" << zero << "\n" << positive << "\n";
}

// 이번엔 세 가지 색깔 영역 개수 구하기
// 2630에서 코드만 약간 바꿔주면 돼