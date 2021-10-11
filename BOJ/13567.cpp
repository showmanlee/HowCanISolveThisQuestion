// 로봇
// https://www.acmicpc.net/problem/13567

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	int dir = 2;
	int x = 0, y = 0;
	bool fail = false;
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		if (fail) {
			continue;
		}
		if (s == "MOVE") {
			x += dx[dir] * p;
			y += dy[dir] * p;
			if (x < 0 || y < 0 || x > m || y > m)
				fail = true;
		}
		else if (s == "TURN") {
			if (p == 0) {
				dir = (dir + 3) % 4;
			}
			else {
				dir = (dir + 1) % 4;
			}
		}
	}
	if (fail) {
		cout << -1 << '\n';
	}
	else {
		cout << x << ' ' << y << '\n';
	}
}

// m*m 정사각형 격자에서 이동/회전 명령을 내릴 때, 최종 결과가 유효(명령어 수행 중 보드 밖으로 나가지 않음)하다면 최종 위치 출력하기

// 초기 시작 위치는 (0, 0), 방향은 동쪽(x가 양으로 늘어나는 방향)
// 이동은 현재 보고 있는 방향으로 p칸 이동하고, 회전은 입력에 따라 좌/우측으로 90도 회전
// 만약 위 과정을 반복하며 한 번이라도 보드를 벗어났다면 fail 플래그를 띄워 무조건 결과가 -1이 나오도록 설정
// 그렇지 않다면 최종 위치 출력하기