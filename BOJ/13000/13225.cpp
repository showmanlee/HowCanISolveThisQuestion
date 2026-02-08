// Divisors
// https://www.acmicpc.net/problem/13225

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) {
				res++;
			}
		}
		cout << n << ' ' << res << '\n';
	}
}

// n을 나누어떨어지게 하는 수의 개수 구하기