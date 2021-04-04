// 쿼드트리
// https://www.acmicpc.net/problem/1992

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string dq(vector<vector<char>>& board, int x, int y, int size) {
	if (size == 0)
		return "";
	string ret = "";
	bool same = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++)
			if (board[i][j] != board[x][y])
				same = false;
		if (!same)
			break;
	}
	if (same)
		ret += board[x][y];
	else {
		int p = size / 2;
		ret += "(";
		ret += dq(board, x, y, p);
		ret += dq(board, x, y + p, p);
		ret += dq(board, x + p, y, p);
		ret += dq(board, x + p, y + p, p);
		ret += ")";
	}
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			board[i][j] = s[j];
	}
	cout << dq(board, 0, 0, n) << endl;
}

// 분할 정복
// 분할되는 경우에만 괄호 씌워주기
