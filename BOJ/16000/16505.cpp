// 별
// https://www.acmicpc.net/problem/16505

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void f(int x, int y, int p, vector<vector<char>>& v) {
	v[x][y] = '*';
	if (p == 1) {
		return;
	}
	f(x + p / 2, y, p / 2, v);
	f(x, y + p / 2, p / 2, v);
	f(x, y, p / 2, v);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = pow(2, n);
	vector<vector<char>> board(p, vector<char>(p, ' '));
	f(0, 0, p, board);
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p - i; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

// 주어진 대로 별 찍기