// 세 개의 소수 문제
// https://www.acmicpc.net/problem/11502

#include <iostream>
#include <vector>
#include <string>
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
    int p = size(prime);
    
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        bool res = 0;
        for (int i = 0; i < p; i++) {
            for (int j = i; j < p; j++) {
                for (int k = j; k < p; k++) {
                    if (prime[i] + prime[j] + prime[k] == n) {
                        cout << prime[i] << ' ' << prime[j] << ' ' << prime[k] << '\n';
                        res = true;
                        break;
                    }
                }
                if (res) {
                    break;
                }
            }
            if (res) {
                break;
            }
        }
        if (!res) {
            cout << 0 << '\n';
        }
    }
}

// 주어진 홀수를 세 개의 소수의 합으로 표현한 결과 출력하기

// 홀수가 1000까지만 주어지므로 그 안에서 브루트포스로 구할 수 있음