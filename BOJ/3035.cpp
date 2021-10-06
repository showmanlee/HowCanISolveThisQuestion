// 스캐너
// https://www.acmicpc.net/problem/3035

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;
	vector<vector<char>> board(r, vector<char>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];
	for (int i = 0; i < r * zr; i++) {
		for (int j = 0; j < c * zc; j++)
			cout << board[i / zr][j / zc];
		cout << '\n';
	}
}

// 주어진 문양을 zr*zc배 확대하기

// r*c 크기의 패턴을 배열로 받은 뒤, r*zr / c*rc 크기의 반복문을 돌리면서 확장된 각 칸에 [i / zr][j / zc] 출력하기