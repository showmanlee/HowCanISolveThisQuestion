// 골드바흐의 추측
// https://www.acmicpc.net/problem/6588

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(1000001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(1000001); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= 1000000; j += i)
				prime[j] = false;
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		bool fail = true;
		for (int i = 1; i <= n / 2; i++) {
			if (prime[i] && prime[n - i]) {
				cout << n << " = " << i << " + " << (n - i) << '\n';
				fail = false;
				break;
			}
		}
		if (fail)
			cout << "Goldbach's conjecture is wrong.\n";
	}
}

// '4보다 큰 짝수는 모두 소수의 합으로 나타낼 수 있다'는 골드바흐의 추측에 따라, 주어진 짝수를 차이가 가장 큰 소수의 합으로 나타내기(안 될 수도 있음)
// 에라토스테네스의 체를 이용해 입력 범위인 1000000까지의 소수를 구한 후, 1부터 n의 절반까지 올려가며 i와 n - i가 모두 소수인 케이스를 찾기
// 사실, 안 되는 경우는 단 한 케이스밖에 없음