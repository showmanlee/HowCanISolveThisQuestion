// 푸앙이와 종윤이
// https://www.acmicpc.net/problem/25591

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y;
	cin >> x >> y;
	int a = 100 - x;
	int b = 100 - y;
	int c = 100 - (a + b);
	int d = a * b;
	int q = d / 100;
	int r = d % 100;
	int resf = c + q;
	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n' << resf << ' ' << r << '\n';
}

// 베다수학 곱셈 과정 출력하기

// 문제에 나온 대로 계산하여 출력한다 - 다 나와 있음