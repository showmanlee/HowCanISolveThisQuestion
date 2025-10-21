// Tic-Tac-Toe AI
// https://www.acmicpc.net/problem/34386

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char p;
	cin >> p;
	vector<vector<char>> board(4, vector<char>(4));
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> board[i][j];
		}
	}
	int resx = 0, resy = 0;
	for (int i = 1; i <= 3; i++) {
		int a = 0, b = 0, t = 0;
		for (int j = 1; j <= 3; j++) {
			if (board[i][j] == p) {
				a++;
			} else if (board[i][j] == 'E') {
				b++;
				t = j;
			}
		}
		if (a == 2 && b == 1) {
			resx = i;
			resy = t;
			break; 
		}
		a = 0; b = 0; t = 0;
		for (int j = 1; j <= 3; j++) {
			if (board[j][i] == p) {
				a++;
			} else if (board[j][i] == 'E') {
				b++;
				t = j;
			}
		}
		if (a == 2 && b == 1) {
			resx = t;
			resy = i;
			break; 
		}
	}
	if (resx == 0) {
		string s;
		s += board[1][1];
		s += board[2][2];
		s += board[3][3];
		int a = 0, b = 0, t = 0;
		for (int j = 1; j <= 3; j++) {
			if (s[j - 1] == p) {
				a++;
			} else if (s[j - 1] == 'E') {
				b++;
				t = j;
			}
		}
		if (a == 2 && b == 1) {
			resx = resy = t;
		}
	}
	if (resx == 0) {
		string s;
		s += board[1][3];
		s += board[2][2];
		s += board[3][1];
		int a = 0, b = 0, t = 0;
		for (int j = 1; j <= 3; j++) {
			if (s[j - 1] == p) {
				a++;
			} else if (s[j - 1] == 'E') {
				b++;
				t = j + 1;
			}
		}
		if (a == 2 && b == 1) {
			resx = t;
			resy = 4 - t;
		}
	}
	cout << resx << ' ' << resy << '\n';
}

// 빈칸이 있는 틱택토판이 주어질 때 현재 플레이어의 승으로 보드 채우기