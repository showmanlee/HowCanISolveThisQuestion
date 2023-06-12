// 뒤집어진 소수
// https://www.acmicpc.net/problem/10859

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	bool res = true;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = false;
			break;
		}
	}
	if (n == 1) {
		res = false;
	}
	if (res) {
		long long r = 0;
		long long nn = n;
		while (nn > 0) {
			long long d = nn % 10;
			if (d == 3 || d == 4 || d == 7) {
				res = false;
				break;
			} else if (d == 6) {
				d = 9;
			} else if (d == 9) {
				d = 6;
			}
			r *= 10;
			r += d;
			nn /= 10;
		}
		if (res) {
			for (long long i = 2; i * i <= r; i++) {
				if (r % i == 0) {
					res = false;
					break;
				}
			}
		}
	}
	cout << (res ? "yes" : "no") << '\n';
}

// 주어진 수가 원래도, 뒤집혀도 소수인지 판정하기

// 수가 뒤집히면 자리기 뒤집히고, 6과 9가 서로 바뀐다 - 다만 3, 4, 7이 들어간 수는 더 이상 수가 아니게 된다
// 이를 이용해 뒤집힌 수를 구하고, 두 수가 소수인지 판정히기
// 수가 long long 범위로 주어지지만, sqrt까지 소수 판정을 돌리면 풀 수 있음