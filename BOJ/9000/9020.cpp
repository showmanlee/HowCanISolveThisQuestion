// 골드바흐의 추측
// https://www.acmicpc.net/problem/9020

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(10001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(10001); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= 10000; j += i)
				prime[j] = false;
		}
	}
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		for (int i = n / 2; i > 0; i--) {
			if (prime[i] && prime[n - i]) {
				cout << i << ' ' << (n - i) << '\n';
				break;
			}
		}
	}
}

// '2보다 큰 짝수는 모두 소수의 합으로 나타낼 수 있다'는 골드바흐의 추측에 따라, 주어진 짝수를 차이가 가장 작은 소수의 합으로 나타내기
// 에라토스테네스의 체를 이용해 입력 범위인 10000까지의 소수를 구한 후, n의 절반부터 시작하여 소수를 구해가면 됨