// V for Vendetta
// https://www.acmicpc.net/problem/26510

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				cout << ' ';
			}
			cout << '*';
			if (i == n - 1) {
				cout << '\n';
				break;
			}
			for (int j = 0; j < (n - i - 1) * 2 - 1; j++) {
				cout << ' ';
			}
			cout << '*' << '\n';
		}
	}
}

// 주어진 대로 v들 그리기