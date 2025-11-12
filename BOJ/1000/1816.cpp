// 암호 키
// https://www.acmicpc.net/problem/1816

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> isprime(1000001, true);
	vector<long long> prime;
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

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long n;
		cin >> n;
		bool res = true;
		for (long long i : prime) {
			if (n % i == 0) {
				res = false;
				break;
			}
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 주어진 정수의 소인수 중 100만 이하의 수가 있는지 확인하기