// Dates
// https://www.acmicpc.net/problem/3183

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int d, m, y;
		cin >> d >> m >> y;
		if (d == 0 && m == 0 && y == 0) {
			break;
		}
		bool res = true;
		if (m <= 0 || m > 12) {
			res = false;
		} else if (d <= 0 || d > 31) {
			res = false;
		} else {
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				res = d <= 31;
			} else if (m == 2) {
				res = d <= ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28);
			} else {
				res = d <= 30;
			}
		}
		cout << (res ? "Valid" : "Invalid") << '\n';
	}
}

// 주어진 날짜가 맞는지 구하기