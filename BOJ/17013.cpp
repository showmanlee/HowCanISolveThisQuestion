// Flipper
// https://www.acmicpc.net/problem/17013

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> board = {
		{1, 2},
		{3, 4}
	};

	string s;
	cin >> s;
	for (char c : s) {
		if (c == 'H') {
			swap(board[0][0], board[1][0]);
			swap(board[0][1], board[1][1]);
		}
		else {
			swap(board[0][0], board[0][1]);
			swap(board[1][0], board[1][1]);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

// 1234가 채워진 2*2 보드를 주어진 대로 뒤집었을 때 나오는 결과 출력하기

// H는 수평축으로 뒤집고, V는 수직축으로 뒤집는다
// swap을 이용해 주어진 대로 뒤집은 후, 출력하기