// 다음 소수
// https://www.acmicpc.net/problem/4134

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
	if (n < 2) {
		return false;
	}
	for (long long i = 2; i <= sqrt(n + 1); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long n;
		cin >> n;
		while (!isPrime(n)) {
			n++;
		}
		cout << n << '\n';
	}
}

// 주어진 수보다 크거나 같은 가장 작은 소수 구하기

// 에라토스테네스를 이용해 소수 구하기 - 2부터 sqrt(n + 1)까지 나누어떨어지지 않으면 소수
// 소수가 될 떄까지 1씩 올려가며 에라토스테네스를 돌려본다 - 그래도 가능함
// 4 * 10^9는 long long 범위임에 주의