// Дробь
// https://www.acmicpc.net/problem/21412

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> isprime(1001, true);
	vector<int> prime;
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= sqrt(1001); i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 1000; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= 1000; i++) {
		if (isprime[i]) {
			prime.push_back(i);
		}
	}

	int n;
	cin >> n;
	for (int i = n / 2; i >= 1; i--) {
		int j = n - i;
		bool pass = true;
		for (int p : prime) {
			if (i % p == 0 && j % p == 0) {
				pass = false;
				break;
			}
		}
		if (pass) {
			cout << i << ' ' << j << '\n';
			break;
		}
	}
}

// 분모와 분자의 합이 n인 가장 큰 기약분수 출력하기