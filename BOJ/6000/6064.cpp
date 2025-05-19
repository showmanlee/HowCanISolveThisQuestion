// 카잉 달력
// https://www.acmicpc.net/problem/6064

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		
		int res = -1;
		for (int i = x; i <= lcm(m, n); i += m) {
			int p = i % n;
			if (p == 0) {
				p = n;
			}
			if (p == y) {
				res = i;
				break;
			}
		}
		cout << res << '\n';
	}
}

// 카잉 달력 형태로 주어지는 값에서 몇 년째인지 구하기