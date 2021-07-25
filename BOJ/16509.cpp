// 장군
// https://www.acmicpc.net/problem/16509

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[8][3] = {
	{-1, -1, -1},
	{-1, -1, -1},
	{0, -1, -1},
	{0, 1, 1},
	{1, 1, 1},
	{1, 1, 1},
	{0, 1, 1},
	{0, -1, -1}
};
int dy[8][3] = {
	{0, -1, -1},
	{0, 1, 1},
	{1, 1, 1},
	{1, 1, 1},
	{0, 1, 1},
	{0, -1, -1},
	{-1, -1, -1},
	{-1, -1, -1}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	vector<vector<int>> visit(10, vector<int>(9, -1));
	visit[sx][sy] = 0;
	queue<pr> q;
	q.push({ sx, sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == gx && y == gy)
			break;
		for (int i = 0; i < 8; i++) {
			int xx = x;
			int yy = y;
			bool dnf = false;
			for (int j = 0; j < 3; j++) {
				if (xx == gx && yy == gy) {
					dnf = true;
					break;
				}
				xx += dx[i][j];
				yy += dy[i][j];
			}
			if (xx < 0 || yy < 0 || xx >= 10 || yy >= 9)
				dnf = true;
			if (dnf)
				continue;
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				q.push({ xx, yy });
			}
		}
	}
	cout << visit[gx][gy] << '\n';
}

// 장기판에서 상이 왕을 잡기 위해 움직여야 하는 최소 이동 횟수는?

// 상은 상하좌우로 한 칸 이동한 후 같은 방향 대각선으로 연속 2칸을 이동한다 - 이 경로에서 다른 말을 뛰어넘을 수 없음
// 따라서 말을 움직일 때 한 칸씩 움직여서 다른 말(왕)과 중간에 만나는지 확인해야 함
// bfs에서 말을 한 칸 움직이기 전, 현재 위치에 왕도 있는지 확인 - 있으면 더 이상 진행 불가
// 이렇게 말을 한칸씩 옮긴 후, 옮긴 위치가 보드 밖이라도 진행 불가 - 두 조건을 모두 통과하면 visit에 기록하고 다음 탐색 돌입
// 결과적으로 왕과 만나게 되면 탐색을 종료하고 출력하기