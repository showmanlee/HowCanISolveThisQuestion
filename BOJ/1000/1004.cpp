// 어린 왕자
// https://www.acmicpc.net/problem/1004

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isInside(int x, int y, int r, int px, int py) {
	int xx = (x - px) * (x - px);
	int yy = (y - py) * (y - py);
	return xx + yy <= r * r;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int n;
		cin >> n;
		int res = 0;
		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			bool a = isInside(x, y, r, sx, sy);
			bool b = isInside(x, y, r, ex, ey);
			if (a != b) {
				res++;
			}
		}
		cout << res << '\n';
	}
}

// 2차원 공간의 두 점과 원들이 주어질 때, 원을 최대한 가로지르지 않고 가는 횟수 구하기