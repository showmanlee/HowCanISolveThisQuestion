// Population
// https://www.acmicpc.net/problem/26561

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		a -= (b / 7);
		a += (b / 4);
		cout << a << '\n';
	}
}

// 7초에 1명이 죽고, 4초에 1명이 태어날 때, a명에서 b초 후 인구 구하기

// b/7을 빼고, b/4를 더한다