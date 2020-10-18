// 분해합
// https://www.acmicpc.net/problem/2231

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p = i, q = i;
		while (q > 0) {
			p += q % 10;
			q /= 10;
		}
		if (p == n) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}
