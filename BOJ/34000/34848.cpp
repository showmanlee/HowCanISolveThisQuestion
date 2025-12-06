// 저녁 메뉴 월드컵
// https://www.acmicpc.net/problem/34848

#include <iostream>
#include <vector>
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
		int res = 0;
		while (n > 1) {
			res += n % 2;
			n = (n / 2) + (n % 2);
		}
		cout << res << '\n';
	}
}

// n명이 토너먼트를 할 때, 부전승의 수 구하기