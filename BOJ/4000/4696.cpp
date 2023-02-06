// St. Ives
// https://www.acmicpc.net/problem/4696

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	while (true) {
		float p;
		cin >> p;
		if (p == 0) {
			break;
		}
		float res = 0;
		for (int i = 0; i <= 4; i++) {
			res += pow(p, i);
		}
		cout << res << '\n';
	}
}

// 실수 p에 대해 p^0 + p^1 + p^2 + p^3 + p^4 구하기

// p^0 == 1이니까 반복문으로 0부터 4까지 돌려서 구하면 되지요