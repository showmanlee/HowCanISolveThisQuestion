// Testing LEDs
// https://www.acmicpc.net/problem/33652

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = -1;
	for (int i = 0; i < n; i++) {
		int p, t;
		cin >> p >> t;
		if (t == 0) {
			if (res == -1) {
				res = p;
			} else {
				res = min(res, p);
			}
		}
	}
	cout << res << '\n';
}

// 불이 켜지고 꺼진 시점이 랜덤하게 주어질 때, 가장 처음으로 꺼진 시점 구하기