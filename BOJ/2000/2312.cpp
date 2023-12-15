// 수 복원하기
// https://www.acmicpc.net/problem/2312

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<bool> isprime(100001, true);
	vector<int> prime;
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= sqrt(100001); i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 100000; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= 100000; i++) {
		if (isprime[i]) {
			prime.push_back(i);
		}
	}

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        vector<int> cnt(100001);
        for (int i : prime) {
            if (n == 1) {
                break;
            }
            while (n % i == 0) {
                n /= i;
                cnt[i]++;
            }
        }
        for (int i : prime) {
            if (cnt[i] != 0) {
                cout << i << ' ' << cnt[i] << '\n';
            }
        }
    }
}

// 주어진 수를 소인수분해하기

// 하면 됩니다 - 에라토스테네스로 소수 구해서 하세요