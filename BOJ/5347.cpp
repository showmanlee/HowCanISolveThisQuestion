// LCM
// https://www.acmicpc.net/problem/5347

#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		long long n = a % b;
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

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		long long res = a * b / gcd(a, b);
		cout << res << '\n';
	}
}

// 두 수의 최소공배수 구하기

// a * b / gcd(a, b)
// a와 b의 최댓값은 1,000,000이지만, 이를 제곱하면 long long 범위가 됨에 주의