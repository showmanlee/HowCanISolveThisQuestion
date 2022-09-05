// 언더프라임
// https://www.acmicpc.net/problem/1124

#include <iostream>
#include <vector>
#include <queue>
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

	int a, b;
	cin >> a >> b;
	int res = 0;
	for (int t = a; t <= b; t++) {
		int cnt = 0;
		int p = t;
		for (int i : prime) {
			while (!(p % i)) {
				cnt++;
				p /= i;
				if (p == 1) {
					break;
				}
			}
			if (p == 1) {
				break;
			}
		}
		if (isprime[cnt] == true) {
			res++;
		}
	}
	cout << res << '\n';
}

// a부터 b까지의 자연수 중 자연수를 소인수분해해서 나오는 소수의 개수가 소수인 자연수 개수 구하기

// 소수 목록이야 에라토스테네스로 구하면 된다 - 여기서 소수 플래그와 소수 목록 배열을 동시에 뽑아둔다
// 이후 자연수를 받아 소인수분해를 하며 나눠질 때마다 카운트를 올리고, 완전히 분해됐을 때 카운트가 소수인 경우 결과값을 누적시킨다