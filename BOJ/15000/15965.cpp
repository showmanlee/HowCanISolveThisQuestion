// K번째 소수
// https://www.acmicpc.net/problem/15965

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<bool> isprime(7500001, true);
	vector<int> prime;
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= sqrt(7500001); i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 7500000; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= 7500000; i++) {
		if (isprime[i]) {
			prime.push_back(i);
		}
	}

    int n;
    cin >> n;
    int idx = 1, cnt = 0;
    while (true) {
        if (isprime[idx]) {
            cnt++;
            if (cnt == n) {
                cout << idx << '\n';
                break;
            }
        }
        idx++;
    }
}

// n번째 소수 구하기