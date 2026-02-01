// Morton Numbers
// https://www.acmicpc.net/problem/9883

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	unsigned long long a, b, res = 0;
	cin >> a >> b;
	unsigned long long p = 1;
	for (int i = 0; i < 16; i++) {
		res += b % 2 * p;
		p *= 2;
		b /= 2;
		res += a % 2 * p;
		p *= 2;
		a /= 2;
	}
	cout << res << '\n';
}

// 주어진 2진수의 비트를 교차해서 출력하기