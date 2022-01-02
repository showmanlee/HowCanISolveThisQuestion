// 베르트랑 공준
// https://www.acmicpc.net/problem/4948

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(246913, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(246913); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= 246913; j += i)
				prime[j] = false;
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		int res = 0;
		for (int i = n + 1; i <= n * 2; i++)
			if (prime[i])
				res++;
		cout << res << '\n';
	}
}

// '임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다'는 베르트랑 공준에 따라, n이 주어질 때 n+1~2n 범위 내의 소수의 개수 구하기
// 입력 범위가 주어져 있기에 246912(123456 * 2)까지의 에레토스테네스의 체를 만들어서 판정해보자
// 이렇듯 입력 범위가 부담없이 주어진다면, 에라토스테네스의 체는 확실한 소수 판별 수단이 된다