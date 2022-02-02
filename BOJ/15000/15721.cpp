// 번데기
// https://www.acmicpc.net/problem/15721

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, t, m;
	cin >> a >> t >> m;
	int z = 0, o = 0, c = 0, r = 2;
	while (true) {
		z++;
		if (t == z && m == 0) {
			break;
		}
		c = (c + 1) % a;
		o++;
		if (t == o && m == 1) {
			break;
		}
		c = (c + 1) % a;
		z++;
		if (t == z && m == 0) {
			break;
		}
		c = (c + 1) % a;
		o++;
		if (t == o && m == 1) {
			break;
		}
		c = (c + 1) % a;
		bool flag = false;
		for (int i = 0; i < r; i++) {
			z++;
			if (t == z && m == 0) {
				flag = true;
				break;
			}
			c = (c + 1) % a;
		}
		if (flag) {
			break;
		}
		for (int i = 0; i < r; i++) {
			o++;\
			if (t == o && m == 1) {
				flag = true;
				break;
			}
			c = (c + 1) % a;
		}
		if (flag) {
			break;
		}
		r++;

	}
	cout << c << '\n';
}

// 번-데기-번-데기-(번*n-1)-(데기*n-1) 순으로 말하는 번데기 게임에 a명이 참가할 때, t번째 번/데기를 말하는 사람은?

// 사실 수 자체가 그리 크지 않으므로 직접 돌려보면 된다 - 저 사이클을 그대로 시뮬레이션하면서 카운트하기