// Shipping
// https://www.acmicpc.net/problem/26530

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		float res = 0;
		for (int i = 0; i < n; i++) {
			string s;
			float a, b;
			cin >> s >> a >> b;
			res += a * b;
		}
		cout << '$' << res << '\n';
	}
}

// 구매한 물품명, 가격, 개수가 주어질 떄, 총합 구하기

// 구하면 되지요...