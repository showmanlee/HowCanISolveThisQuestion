// Monitor DPI
// https://www.acmicpc.net/problem/9317

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	while (true) {
		double d, x, y;
		cin >> d >> x >> y;
		if (d == x && x == y && y == 0) {
			break;
		}
		double w = 16 * d / sqrt(337);
		double h = w * 9 / 16;
		cout << "Horizontal DPI: " << x / w << '\n';
		cout << "Vertical DPI: " << y / h << '\n';
	}
}

// 16:9 모니터의 크기와 가로/세로 픽셀 수가 주어질 때, 가로/세로 DPI 구하기

// 다행히 인치수에서 가로/세로 길이를 구하는 공식이 이미 주어져있음
// 따라서 이 공식을 이용해 가로/세로 인치수를 구한 후, dpi를 구하면 됨