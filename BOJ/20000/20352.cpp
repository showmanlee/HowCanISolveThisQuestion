// Circus
// https://www.acmicpc.net/problem/20352

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double PI = 3.14159265359;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double d;
	cin >> d;
	double r = sqrt(d / PI);
	double res = r * 2 * PI;

	cout << fixed;
	cout.precision(9);
	cout << res << '\n';
}

// 원의 넗이가 주어질 때, 원의 둘레 구하기

// pr^2를 2pr로 바꿔달라는 의미
// 그렇게 계산하면 됩니다 - 출력 자릿수 주의하면서...