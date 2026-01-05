// 1, 2, 3, 많다!
// https://www.acmicpc.net/problem/34998

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		n++;
		int res = 0;
		for (int i = 0; i < n * 2 - 1; i++) {
			char c;
			cin >> c;
			if (i % 2 == 0) {
				if (c == '!') {
					res += 10;
				} else {
					res += c - '0';
				}
			}
		}
		if (res >= 10) {
			cout << "!\n";
		} else {
			cout << res << '\n';
		}
	}
}

// 9 이상을 !으로 표현하는 덧셈식의 결과 구하기