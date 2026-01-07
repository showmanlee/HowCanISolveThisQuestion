// Szachy
// https://www.acmicpc.net/problem/8725

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p = 0;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			p = max(p, t);
		}
		res += p;
	}
	cout << res << '\n';
}

// 각 열에서 가장 높은 수를 골라 더하기