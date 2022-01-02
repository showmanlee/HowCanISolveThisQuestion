// 사토르 마방진
// https://www.acmicpc.net/problem/20112

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> board[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != board[j][i]) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	cout << "YES" << '\n';
	return 0;
}

// 곰돌아
// 돌았니
// 아니오
// 와 같이 (i, i)를 기준으로 가로로 읽으나 세로로 읽으나 똑같은 모양을 가지는지 확인