// 지각
// https://www.acmicpc.net/problem/21335

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(9);

	double d;
	cin >> d;
	cout << (sqrt(d / 3.1415926535) * 2 * 3.1415926535) << '\n';
}

// 원 넓이로 둘레 구하기

// pi * r^2 -> pi * r * 2