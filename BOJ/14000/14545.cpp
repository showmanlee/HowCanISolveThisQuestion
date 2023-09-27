// Square
// https://www.acmicpc.net/problem/14545

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		long long res = 0;
		for (int i = 1; i <= n; i++) {
			res += i * i;
		}
		cout << res << '\n';
	}
}

// 1*1+...+n*n 구하기

// 구하면 됩니다