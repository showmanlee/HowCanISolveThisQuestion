// 래환이의 아이브 콘서트 이야기
// https://www.acmicpc.net/problem/34125

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int resx = 0, resy = 0, resd = 987654321;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int p;
			cin >> p;
			if (p == 0 && resd > i + abs((m + 1) / 2 - j)) {
				resx = i;
				resy = j;
				resd = i + abs((m + 1) / 2 - j);
			}
		}
	}
	if (resd == 987654321) {
		cout << -1;
	} else {
		cout << resx << ' ' << resy;
	}
	cout << '\n';
}

// 빈 좌석표가 주어질 때, 빈 자리 중에서 무대 중앙과 가장 가까운 좌석 구하기