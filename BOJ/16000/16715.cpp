// Inspiration
// https://www.acmicpc.net/problem/16715

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int resa = 0, resb = 0;
	for (int i = 2; i <= n; i++) {
		int p = n;
		int r = 0;
		while (p > 0) {
			r += p % i;
			p /= i;
		}
		if (resa < r) {
			resa = r;
			resb = i;
		}
	}
	cout << resa << ' ' << resb << '\n';
}

// 주어진 수를 2진법에서 n진법까지 표현할 때, 자릿수의 합이 가장 높은 경우 출력하기