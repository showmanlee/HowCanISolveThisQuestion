// 루트
// https://www.acmicpc.net/problem/4619

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	while (true) {
		int b, n;
		cin >> b >> n;
		if (b == 0 && n == 0) {
			break;
		}

		int x = 0;
		int res = -987654321;
		int diff = 987654321;
		while (true) {
			int p = 1;
			for (int i = 0; i < n; i++) {
				p *= x;
			}
			if (diff > abs(b - p)) {
				res = x;
			}
			diff = abs(b - p);
			if (p >= b) {
				break;
			}
			x++;
		}
		cout << res << '\n';
	}
}

// 주어진 정수와 가장 가까운 a^n의 결과를 갖는 a 구하기

// sqrt를 구하기보다는 그냥 돌려보는 게 더 편함 - a^n 결과가 처음으로 b를 넘길 때까지