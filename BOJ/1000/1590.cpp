// 캠프가는 영식
// https://www.acmicpc.net/problem/1590

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	int res = 987654321;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = 0; j < c; j++) {
			int p = a + (b * j);
			if (t <= p) {
				res = min(res, p);
				break;
			}
		}
	}
	if (res == 987654321) {
		res = -1;
	} else {
		res -= t;
	}
	cout << res << '\n';
}

// 버스 현황과 터미널 도착 시간이 주어질 때, 도착하고 탈 수 있는 가장 빠른 버스 시간 구하기