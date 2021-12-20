// 데칼코마니
// https://www.acmicpc.net/problem/23841

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			if (board[i][j] != '.') {
				board[i][j] = board[i][m - j - 1] = board[i][j];
			}
			else if (board[i][m - j - 1] != '.') {
				board[i][j] = board[i][m - j - 1] = board[i][m - j - 1];
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

// 주어진 물감 그림을 가로로 접었을 때 나오는 데칼코마니 패턴 출력하기

// 가로 길이는 언제나 짝수고, 접었을 때 물감이 겹치는 경우는 없음
// 따라서 좌우 대칭 쌍에 물감은 한 쪽이 비어있음이 보장됨
// 대칭 쌍들을 돌면서 빈칸이 아닌 칸의 색으로 빈칸 칠하기