// 특수한 정수 쌍
// https://www.acmicpc.net/problem/34554

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> isprime(100001, true);
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= sqrt(100001); i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 100000; j += i) {
				isprime[j] = false;
			}
		}
	}

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		int a = 1, b = n + 1;
		if (isprime[b]) {
			cout << 1 << '\n' << a << ' ' << b << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}

// a < b이고 b - a = n이며 a * b의 약수의 개수가 2개인 순서쌍 구하기