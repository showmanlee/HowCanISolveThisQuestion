// 소수의 자격
// https://www.acmicpc.net/problem/6219

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(4000001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(4000001); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= 4000000; j += i)
				prime[j] = false;
		}
	}
	int a, b, d;
	cin >> a >> b >> d;
	int res = 0;
	for (int i = a; i <= b; i++) {
		if (prime[i]) {
			int p = i;
			while(p > 0) {
				if (p % 10 == d) {
					res++;
					break;
				}
				p /= 10;
			}
		}
	}
	cout << res << '\n';
}

// a부터 b까지의 소수 중 숫자 d가 들어간 소수의 수는?

// 에라토스테네스로 최대 범위(400만)까지의 소수를 구해두고, 각 범위 안에서 소수에게 해당 숫자가 등장하는지 직접 확인해봅시다