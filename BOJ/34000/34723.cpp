// 피막치
// https://www.acmicpc.net/problem/34723

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p, m, c, x;
	cin >> p >> m >> c >> x;
	int res = 1987654321;
	for (int i = 1; i <= p; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= c; k++) {
				res = min(res, abs((i + j) * (j + k) - x));
			}
		}
	}
	cout << res << '\n';
}

// 1~p, 1~m, 1~c 범위에서 abs((p + m) * (m + c) - x)의 최솟값 구하기