// СРЕЩА НА ПРИЯТЕЛИ
// https://www.acmicpc.net/problem/24333

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	int ll = max(l1, l2);
	int rr = min(r1, r2);
	int res = rr - ll + 1;
	if (ll <= k && k <= rr) {
		res--;
	}
	if (res < 0) {
		res = 0;
	}
	cout << res << '\n';
}

// 두 사람의 비는 시간, 만날 수 없는 1분이 주어질 때, 몇 분 동안 만날 수 있는지 구하기