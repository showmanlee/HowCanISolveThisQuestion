// 전구 주기 맞추기
// https://www.acmicpc.net/problem/32403

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (t % p != 0) {
			int m = 0;
			while (true) {
				m++;
				if (p - m > 0) {
					if (t % (p - m) == 0) {
						res += m;
						break;
					}
				}
				if (t % (p + m) == 0) {
					res += m;
					break;
				}
			}
		}
	}
	cout << res << '\n';
}

// 각자의 주기로 켜지는 전구 n개를 모두 t초에 켜려고 할 때 조작해야 하는 주기 조정 스위치 횟수 구하기