// 지영 공주님의 마법 거울
// https://www.acmicpc.net/problem/11586

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int k;
	cin >> k;
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << board[i][j];
			cout << '\n';
		}
	}
	else if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << board[i][n - j - 1];
			cout << '\n';
		}
	}
	else if (k == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << board[n - i - 1][j];
			cout << '\n';
		}
	}
}

// n*n 보드를 그대로/좌우반전한/상하반전한 결과 출력하기

// 좌우반전은 j축, 상하반전은 i축을 뒤집어 출력