// X に最も近い値 (The Nearest Value)
// https://www.acmicpc.net/problem/18414

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int x, l, r;
	cin >> x >> l >> r;
	if (l <= x && x <= r) {
		cout << x;
	} else if (r < x) {
		cout << r;
	} else if (l > x) {
		cout << l;
	}
}

// l~r 범위와 x가 주어질 때, l~r 범위에서 x와 가장 가까운 정수 출력하기

// 범위 안에 있으면 x, 밖에 있으면 l,r 중 가까운 수 출력하기