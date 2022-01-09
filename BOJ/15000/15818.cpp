// 오버플로우와 모듈러
// https://www.acmicpc.net/problem/15818

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	long long m;
	cin >> m;
	long long res = 1;
	for (int i = 0; i < n; i++) {
		long long p;
		cin >> p;
		res *= (p % m);
		res %= m;
	}
	cout << res << '\n';
}

// 주어진 수들의 곱을 m으로 나눈 나머지 구하기

// (a * b) % m = ((a % m) * (b % m)) % m
// p % m = p (p < m)
// 이 두 가지만 기억하고, long long 범위에서 계산하기