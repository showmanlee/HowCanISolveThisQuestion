// Euclid
// https://www.acmicpc.net/problem/9884

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int n = a % b;
		if (n == 0)
			return b;
		else {
			a = b;
			b = n;
		}
	}
	return 1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << '\n';
}

// 두 수의 최대공약수 구하기

// 함수로 구하면 되지