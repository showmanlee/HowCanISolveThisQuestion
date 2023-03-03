// 거북이
// https://www.acmicpc.net/problem/8911

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		cin >> s;
		int minx = 0, maxx = 0, miny = 0, maxy = 0;
		int x = 0, y = 0, dir = 0;
		for (char c : s) {
			if (c == 'F') {
				x += dx[dir];
				y += dy[dir];
			} else if (c == 'B') {
				x -= dx[dir];
				y -= dy[dir];
			} else if (c == 'L') {
				dir = (dir + 3) % 4;
			} else if (c == 'R') {
				dir = (dir + 1) % 4;
			}
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
		}
		cout << ((maxx - minx) * (maxy - miny)) << '\n';
	}
}

// 좌표평면 위에서 앞/뒤/좌회전/우회전이 가능한 거북이가 있고 거북이에게 준 명령이 주어질 때, 해당 명령대로 움직여서 얻을 수 있는 범위를 포함하는 직사각형의 구하기

// 명령대로 좌표와 방향을 움직이며 최소 좌표값과 최대 좌표값을 구하고, 해당 좌표값을 이용해 직사각형의 넓이를 구해줍니다