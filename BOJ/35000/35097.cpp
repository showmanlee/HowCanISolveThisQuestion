// 2025
// https://www.acmicpc.net/problem/35097

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				res += i * j;
			}
		}
		cout << res << '\n';
	}
}

// 1부터 n까지의 모든 쌍의 곱의 합 출력하기