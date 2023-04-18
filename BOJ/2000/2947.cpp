// 나무 조각
// https://www.acmicpc.net/problem/2947

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	while (a != 1 || b != 2 || c != 3 || d != 4 || e != 5) {
		if (a > b) {
			swap(a, b);
			cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
		}
		if (b > c) {
			swap(b, c);
			cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
		}
		if (c > d) {
			swap(c, d);
			cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
		}
		if (d > e) {
			swap(d, e);
			cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
		}
	}
}

// 1부터 5까지의 숫자가 무작위로 주어졌을 떄, 앞에서부터 버블 정렬하여 오름차순이 되는 과정 출력하기

// 버블 정렬 시뮬레이터