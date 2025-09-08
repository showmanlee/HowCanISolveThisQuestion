// Koncert
// https://www.acmicpc.net/problem/7947

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		double r = 0, g = 0, b = 0;
		for (int i = 0; i < 10; i++) {
			double rr, gg, bb;
			cin >> rr >> gg >> bb;
			r += rr;
			g += gg;
			b += bb;
		}
		r /= 10.0;
		g /= 10.0;
		b /= 10.0;
		cout << ((int)(r + 0.5)) << ' ' << ((int)(g + 0.5)) << ' ' << ((int)(b + 0.5)) << '\n';
	}
}

// 10가지 컬러 코드의 평균 구하기