// 컴백홈
// https://www.acmicpc.net/problem/1189

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int r, c, k;
int res;
char board[5][5];
bool visit[5][5];

void bf(int x, int y, int count) {
	if (x == 0 && y == c - 1) {
		if (count == k)
			res++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= r || yy >= c)
			continue;
		if (board[xx][yy] == '.' && !visit[xx][yy]) {
			visit[xx][yy] = true;
			bf(xx, yy, count + 1);
			visit[xx][yy] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];
	res = 0;
	visit[r - 1][0] = true;
	bf(r - 1, 0, 1);
	cout << res << '\n';
}

// 장애물이 있는 r*c 보드에서 좌측 하단에서 우측 상단으로 이동할 때, 한 번 들른 지점을 다시 접근하지 않는 경로 중 거리가 k인 경로의 수는?
// 큐 기반의 bfs 문제가 아님 - 스택 기반의 브포 문제
// 우측 하단에서 출발하는 것부터 경로 길이로 계산하여 브포를 돌려보자 - 매개변수를 x, y, 거리로 받음
// 브포이니만큼 visit는 재귀 들어가기 전 체크하고, 나가고 난 후 해제하기
