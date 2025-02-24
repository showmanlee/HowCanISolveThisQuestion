// 수열의 극한값
// https://www.acmicpc.net/problem/26518

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(16);

	double b, c, y, z;
	cin >> b >> c >> y >> z;
	double res = (b + sqrt(b * b + c * 4)) / 2.0;
	cout << res << '\n';
}

// a(n) = b * a(n-1) + c * a(n-2) 꼴의 수열에서 a(n)/a(n-1)의 극한값 구하기