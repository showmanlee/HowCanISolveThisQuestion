// 소수 최소 공배수
// https://www.acmicpc.net/problem/21919

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		unsigned long long n = a % b;
		if (n == 0)
			return b;
		else {
			a = b;
			b = n;
		}
	}
	return 1;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
	return a * b / gcd(a, b);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> isprime(1000001, true);
	vector<int> prime;
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= sqrt(1000001); i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 1000000; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		if (isprime[i]) {
			prime.push_back(i);
		}
	}

	int n;
	cin >> n;
	vector<unsigned long long> v;
	for (int i = 0; i < n; i++) {
		unsigned long long p;
		cin >> p;
		if (isprime[p]) {
			v.push_back(p);
		}
	}
	if (v.empty()) {
		cout << -1 << '\n';
	} else if (v.size() == 1) {
		cout << v[0] << '\n';
	} else {
		unsigned long long res = v[0];
		for (int i = 1; i < v.size(); i++) {
			res = lcm(res, v[i]);
		}
		cout << res << '\n';
	}
}

// 주어진 수열의 소수들의 최소공배수 구하기