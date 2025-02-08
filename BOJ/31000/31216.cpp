// 슈퍼 소수
// https://www.acmicpc.net/problem/31216

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<bool> isprime(330000, true);
	vector<int> prime, pprime;
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= sqrt(330000); i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 330000; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= 330000; i++) {
		if (isprime[i]) {
			prime.push_back(i);
		}
	}
    pprime.push_back(0);
    for (int i = 0; i < prime.size(); i++) {
        if (isprime[i + 1]) {
			pprime.push_back(prime[i]);
		}
    }

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
		cout << pprime[n] << '\n';
    }
}

// i번째로 큰 소수인데 i도 소수임을 만족하는 수열에서 n번째 수 구하기