// 3 つの箱 (Three Boxes)
// https://www.acmicpc.net/problem/27325

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = 1;
	int res = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'L') {
			p = max(1, p - 1);
		} else if (c == 'R') {
			p = min(3, p + 1);
		}
		if (p == 3) {
			res++;
		}
	}
	cout << res << '\n';
}

// 1~3번 상자 중 1번 상자에서 죄우로 공을 움직여 다른 상자에 넣을 때, 3번 상자에 들어가는 횟수 구하기