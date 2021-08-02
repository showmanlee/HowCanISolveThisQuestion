// 미로 만들기
// https://www.acmicpc.net/problem/1347

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

	vector<vector<bool>> visit(101, vector<bool>(101));
	int dir = 2;
	int x = 50, y = 50;
	int minx = 50, miny = 50, maxx = 50, maxy = 50;
	int n;
	cin >> n;
	string s;
	cin >> s;
	visit[x][y] = true;
	for (char c : s) {
		if (c == 'F') {
			x += dx[dir];
			y += dy[dir];
			visit[x][y] = true;
			minx = min(x, minx);
			miny = min(y, miny);
			maxx = max(x, maxx);
			maxy = max(y, maxy);
		}
		if (c == 'R')
			dir = (dir + 1) % 4;
		if (c == 'L')
			dir = (dir + 3) % 4;
	}
	for (int i = minx; i <= maxx; i++) {
		for (int j = miny; j <= maxy; j++)
			cout << (visit[i][j] ? '.' : '#');
		cout << '\n';
	}
}

// 처음에 남쪽을 보고 서있는 사람의 이동 및 90도 회전 방향 순서가 주어질 때, 도달한 영역 그리기

// 기록에 따라 이동하고 회전하면서 이동한 자리에 마킹한 뒤, 최종적으로 마킹한 맵을 그려주면 되는 문제 - 다만 맵을 동적으로 확장하기는 어려움
// 기록이 최대 50글자까지 제공되므로, 마킹용 맵의 최대 크기는 101*101로 설정하면 됨
// 그렇게 되면 초기 시작 위치는 50,50 - 여기서 범위를 판정하기 위해 x,y 좌표의 최대/최소 값도 기록할 수 있도록 할당
// 이후 기록에 따라 이동/회전하면서 이동하는 경우 이동한 위치에 따라 최대/최소 좌표값을 갱신
// 이렇게 구한 최대/최소 좌표값을 범위삼아 방문한 곳은 ., 그렇지 않은 곳은 #을 출력하기