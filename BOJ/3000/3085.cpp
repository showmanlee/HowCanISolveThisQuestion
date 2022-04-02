// 사탕 게임
// https://www.acmicpc.net/problem/3085

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		char c = ' ';
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (c == board[i][j]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			res = max(res, cnt);
			c = board[i][j];
		}
		c = ' ';
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (c == board[j][i]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			res = max(res, cnt);
			c = board[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(board[i][j], board[i][j + 1]);
			char c = ' ';
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (c == board[i][k]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				res = max(res, cnt);
				c = board[i][k];
			}
			c = ' ';
			cnt = 0;
			for (int k = 0; k < n; k++) {
				if (c == board[k][j]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				res = max(res, cnt);
				c = board[k][j];
			}
			c = ' ';
			cnt = 0;
			for (int k = 0; k < n; k++) {
				if (c == board[k][j + 1]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				res = max(res, cnt);
				c = board[k][j + 1];
			}
			swap(board[i][j], board[i][j + 1]);

			swap(board[j][i], board[j + 1][i]);
			c = ' ';
			cnt = 0;
			for (int k = 0; k < n; k++) {
				if (c == board[k][i]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				res = max(res, cnt);
				c = board[k][i];
			}
			c = ' ';
			cnt = 0;
			for (int k = 0; k < n; k++) {
				if (c == board[j][k]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				res = max(res, cnt);
				c = board[j][k];
			}
			c = ' ';
			cnt = 0;
			for (int k = 0; k < n; k++) {
				if (c == board[j + 1][k]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				res = max(res, cnt);
				c = board[j + 1][k];
			}
			swap(board[j][i], board[j + 1][i]);
		}
	}
	cout << res << '\n';
}

// n*n 보드에 4가지 색의 사탕이 채워져있고, 색이 다른 인접한 두 사탕 위치를 바꾼 뒤 일렬로 나열된 같은 색 사탕 최대 개수 구하기

// 연속된 사탕 구하는 건 실제로 순회하면서 구하면 된다 - 그래서 원래 상태에서 답을 한 번 구해놓고
// 위치 교환 후 답 구하는 건 전체를 돌 필요 없이 바뀐 행열 3개만 보면 된다 - 이렇게 또 답을 구한다