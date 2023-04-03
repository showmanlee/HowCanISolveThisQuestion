// 수학적 호기심
// https://www.acmicpc.net/problem/9094

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		int res = 0;
		for (int a = 1; a < n - 1; a++) {
			for (int b = a + 1; b < n; b++) {
				if ((a * a + b * b + m) % (a * b) == 0) {
					res++;
				}
			}
		}
		cout << res << '\n';
	}
}

// 두 정수 n과 m이 주어졌을 때, 0 < a < b < n인 정수 쌍 (a, b) 중에서 (a^2 + b^2 + m) / (a * b)가 정수인 쌍의 개수를 구하기

// n이 100까지만 주어지므로 브루트포스로 충분히 돌려볼 수 있음 - 나눗셈 결과가 정수면 나누어떨어져야 함