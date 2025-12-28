// 헌혈 대전
// https://www.acmicpc.net/problem/34892

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b, c, d, e, f, g, h;
	cin >> n >> a >> b >> c >> d >> e >> f >> g >> h;
	int res = 0;
	int resx = 0, resy = 0, resz = 0;
	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n - x; y++) {
			int z = n - x - y;
			if (a * x + b * y + c * z == d && e * x + f * y + g * z == h) {
				res++;
				resx = x;
				resy = y;
				resz = z;
			}
		}
	}
	if (res == 1) {
		cout << 0 << '\n' << resx << ' ' << resy << ' ' << resz << '\n';
	} else {
		cout << (res == 0 ? 2 : 1) << '\n';
	}
}

// ax + by + cz = d, ex + fy + gz = h를 만족하는 x, y, z 구하기