// Tren del Fin del Mundo
// https://www.acmicpc.net/problem/30876

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int resx = 0, resy = 100001;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (resy > y) {
			resx = x;
			resy = y;
		}
	}
	cout << resx << ' ' << resy << '\n';
}

// 주어진 좌표 중 가장 남쪽에 있는 좌표 구하기