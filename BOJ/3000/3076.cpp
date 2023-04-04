// 상근이의 체스판
// https://www.acmicpc.net/problem/3076

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, a, b;
	cin >> r >> c >> a >> b;
	for (int i = 0; i < r * a; i++) {
		bool t = i / a % 2;
		for (int j = 0; j < c * b; j++) {
			if (j % b == 0) {
				t = !t;
			}
			cout << (t ? 'X' : '.');
		}
		cout << '\n';
	}
}

// 한 격자의 크기가 a*b인 r*c 크기의 격자 출력하기

// 별 찍기의 더 멋진 버전