// 봄버맨
// https://www.acmicpc.net/problem/16918

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int r, c, n;
	cin >> r >> c >> n;
	vector<vector<int>> board(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char ch;
			cin >> ch;
			if (ch == 'O')
				board[i][j] = 2;
		}
	}
	for (int t = 2; t <= n; t++) {
		if (t % 2 == 0) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (board[i][j] == 2)
						board[i][j] = 1;
					else if (board[i][j] == 0)
						board[i][j] = 2;
				}
			}
		}
		else {
			vector<vector<bool>> blow(r, vector<bool>(c));
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (board[i][j] == 1) {
						blow[i][j] = true;
						if (i != 0)
							blow[i - 1][j] = true;
						if (j != 0)
							blow[i] [j - 1] = true;
						if (i != r - 1)
							blow[i + 1][j] = true;
						if (j != c - 1)
							blow[i][j + 1] = true;
					}
				}
			}
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (blow[i][j])
						board[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) 
			cout << (board[i][j] != 0 ? 'O' : '.');
		cout << '\n';
	}
}

// 폭탄은 3초 뒤에 터지고, 내 상하좌우에 있는 것도 날려버린다(연쇄 폭발은 없다)
// 최초 -> 대기 -> (설치 -> 폭발) 반복 - 2초 이후 짝수에 채우고 홀수에 이전 폭탄 폭발
// 따라서 폭발 카운트는 2, 1, 0으로 줄일 수 있음
// 폭발 판정 처리 중 이미 휩쓸린 폭탄이 터질 폭탄이었을 수도 있으니 별도의 폭발 배열에 담아주는 게 좋을듯