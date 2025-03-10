// Is It Even?
// https://www.acmicpc.net/problem/24927

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int t = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		while (p % 2 == 0) {
			p /= 2;
			t++;
		}
	}
	cout << (k <= t) << '\n';
}

// n개의 자연수의 곱이 2^k로 나누어떨어지는지 구하기