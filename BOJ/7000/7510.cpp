// 고급 수학
// https://www.acmicpc.net/problem/7510

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) {
			swap(a, b);
		}
		if (b > c) {
			swap(b, c);
		}
		if (a > b) {
			swap(a, b);
		}
		cout << "Scenario #" << t << ":\n";
		cout << (a * a + b * b == c * c ? "yes" : "no") << '\n';
		cout << '\n';
	}
}

// 삼각형의 세 변이 주어질 때 직각삼각형인지 판별하기

// 피타고라스