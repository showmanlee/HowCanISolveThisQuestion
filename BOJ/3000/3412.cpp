// Darts
// https://www.acmicpc.net/problem/3412

#include <iostream>
#include <cmath>
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
		int res = 0;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			double r = std::hypot(x, y);
			if (r > 200.0) {
				continue;
			}
			int p = ceil(r / 20.0);
			p = (x == 0 && y == 0 ? 10 : 11 - p);
			res += p;
		}
		cout << res << '\n';
	}
}

// 원형 다트판에서 점수 구하기