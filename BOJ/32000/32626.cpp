// SPC에 가는 길
// https://www.acmicpc.net/problem/32626

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sx, sy, ex, ey, ax, ay;
	cin >> sx >> sy >> ex >> ey >> ax >> ay;
	int res = 0;
	if (sx == ex) {
		if (ax == sx && (ay < sy != ay < ey)) {
			res = 2;
		} else {
			res = 0;
		}
	} else if (sy == ey) {
		if (ay == sy && (ax < sx != ax < ex)) {
			res = 2;
		} else {
			res = 0;
		}
	} else {
		res = 1;
	}
	cout << res << '\n';
}

// 2차원 보드에서 (sx, sy)에서 (ex, ey)로 이동하면서 (ax, ay)를 밟지 않는 최소 방향 전환 횟수 구하기