// Fifty Coats of Gray
// https://www.acmicpc.net/problem/4697

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n, a, b, c, d, m;
		cin >> n >> a >> b >> c >> d >> m;
		if (a == b && b == c && c == d && d == n && n == m && m == 0) {
			break;
		}
		int area = (a * c * 2) + (b * c * 2) + (a * b);
		area *= n;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			area -= (x * y * n);
		}
		int res = area / d + (area % d > 0 ? 1 : 0);
		cout << res << '\n';
	}
}

// 주어진 방 구조에서 문과 창문 빼고 내부 벽 및 천장에 페인트를 바를 때, 필요한 페인트 수 구하기