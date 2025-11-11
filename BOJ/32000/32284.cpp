// 오늘부터 우리는 (Me gustas tu)
// https://www.acmicpc.net/problem/32284

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<char>> board(n, vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == a) {
				if (j <= b) {
					board[i][j] = 'E';
				} else {
					board[i][j] = 'W';
				}
			} else if (i < a) {
				board[i][j] = 'S';
			} else {
				board[i][j] = 'N';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

// n*m 보드에서 어디서 가더라도 (a,b)에 도달할 수 있는 방향표 구하기