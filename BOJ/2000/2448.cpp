// 별 찍기 - 11
// https://www.acmicpc.net/problem/2448

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char c[3073][6145];

void f(int n, int x, int y) {
	if (n == 3) {
		c[x][y] = '*';
		c[x + 1][y] = '*';
		c[x + 1][y + 2] = '*';
		for (int i = 0; i < 5; i++) {
			c[x + 2][y + i] = '*';
		}
		return;
	}
	f(n / 2, x, y);
	f(n / 2, x + n / 2, y);
	f(n / 2, x + n / 2, y + n);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 3073; i++) {
		for (int j = 0; j < 6145; j++) {
			c[i][j] = ' ';
		}
	}

	int n;
	cin >> n;
	f(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			cout << ' ';
		}
		for (int j = 0; j < (i + 1) * 2 - 1; j++) {
			cout << c[i][j];
		}
		for (int j = 0; j < n - i - 1; j++) {
			cout << ' ';
		}
		cout << '\n';
 	}
}

// 주어진 대로 별 찍기