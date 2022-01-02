// Rectangles
// https://www.acmicpc.net/problem/15232

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << '*';
		cout << '\n';
	}
}

// r*c 크기의 직사각형 출력하기

// 2차원 for 돌면서 그려주면 됩니다