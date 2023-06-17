// 시각
// https://www.acmicpc.net/problem/18312

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int h = 0, m = 0, s = 0;
	int res = 0;
	while (h <= n) {
		if (h % 10 == k || h / 10 == k || m % 10 == k || m / 10 == k || s % 10 == k || s / 10 == k) {
			res++;
		}
		s++;
		if (s == 60) {
			s = 0;
			m++;
			if (m == 60) {
				m = 0;
				h++;
			}
		}
	}
	cout << res << '\n';
}

// 0:00:00부터 n:59:59까지 시각 중 k가 하나 이상 들어가는 시각의 개수는?

// 직접 훑어보며 체크하면 됩니다