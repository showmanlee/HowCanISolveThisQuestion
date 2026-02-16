// Itsy Bits
// https://www.acmicpc.net/problem/35247

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	unsigned long long n;
	cin >> n;
	int res = 0;
	while (n > 0) {
		n /= 2;
		res++;
	}
	int p[8] = {1, 2, 4, 8, 16, 32, 64, 128};
	for (int i = 0; i < 7; i++) {
		if (res <= p[i] && res <= p[i + 1]) {
			res = p[i];
			break;
		}
	}
	cout << res << ' ' << (res == 1 ? "bit" : "bits") << '\n';
}

// 주어진 부호 없는 정수가 몇비트 자료형에 들어가는지 판정하기