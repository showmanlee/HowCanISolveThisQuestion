// 직사각형
// https://www.acmicpc.net/problem/32629

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
		int l = 1, r = 100000;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			int a = m / 2;
			int b = (m + 1) / 2;
			if (a * b < n) {
				l = m;
			} else {
				r = m;
			}
		}
		int res = r * 2;
		cout << res << '\n';
	}
}

// 정사각형 n개를 격자에 배치했을 때 얻을 수 있는 최소 둘레 구하기