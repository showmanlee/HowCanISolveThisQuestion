// 직사각형 네개의 합집합의 면적 구하기
// https://www.acmicpc.net/problem/2669

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<vector<bool>> board(101, vector<bool>(101));
	for (int i = 0; i < 4; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		for (int m = a; m < x; m++)
			for (int n = b; n < y; n++)
				board[m][n] = true;
	}
	int res = 0;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			if (board[i][j])
				res++;
	cout << res << '\n';
}

// 네 개의 직사각형이 만든 총 면적 구하기