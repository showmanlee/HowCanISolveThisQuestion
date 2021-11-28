// 세상은 하나의 손수건
// https://www.acmicpc.net/problem/20493

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	int prog = 0;
	int dir = 0;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		int p;
		string s;
		cin >> p >> s;
		x += dx[dir] * (p - prog);
		y += dy[dir] * (p - prog);
		prog = p;
		if (s == "left") {
			dir = (dir + 3) % 4;
		}
		else {
			dir = (dir + 1) % 4;
		}
	}
	x += dx[dir] * (t - prog);
	y += dy[dir] * (t - prog);
	cout << x << ' ' << y << '\n';
}

// 2차원 좌표평면에서 x축 방향으로 이동 중 특성 위치에서 좌/우회전을 할 때, 최종 도착 지점 출력하기

// 가는 거리는 정해져 있고, 언제 턴을 하는지 나오는 상태(턴 지점들은 정렬되어 주어짐)
// 두 지점 간 간격만큼 이동하고 턴하는 과정을 반복하기