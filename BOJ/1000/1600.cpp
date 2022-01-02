// 말이 되고픈 원숭이
// https://www.acmicpc.net/problem/1600

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int> tpi4;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dx_a[8] = { 2, 2, 1, -1, -2, -2, -1, 1};
int dy_a[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, w, h;
	cin >> k >> w >> h;

	vector<vector<int>> board(h, vector<int>(w));
	vector<vector<vector<bool>>> visit(h, vector<vector<bool>>(w, vector<bool>(k + 1)));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> board[i][j];

	queue<tpi4> q;
	q.push({ 0, 0, 0, 0 });
	visit[0][0][0] = true;
	int res = 987654321;

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int jump = get<2>(q.front());
		int dist = get<3>(q.front());
		q.pop();
		if (x == h - 1 && y == w - 1) {
			res = min(res, dist);
			continue;
		}
		if (jump != k) {
			for (int i = 0; i < 8; i++) {
				int xx = x + dx_a[i];
				int yy = y + dy_a[i];
				if (xx < 0 || yy < 0 || xx >= h || yy >= w || board[xx][yy] == 1)
					continue;
				if (!visit[xx][yy][jump + 1]) {
					visit[xx][yy][jump + 1] = true;
					q.push({ xx, yy, jump + 1, dist + 1 });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= h || yy >= w || board[xx][yy] == 1)
				continue;
			if (!visit[xx][yy][jump]) {
				visit[xx][yy][jump] = true;
				q.push({ xx, yy, jump, dist + 1 });
			}
		}
	}

	if (res == 987654321)
		res = -1;
	cout << res << '\n';
}

// 일반적인 전후좌우 이동, 그리고 k번 사용할 수 있는 나이트 이동법으로 보드 좌측 상단부터 우측 하단까지 이동하는 최단 거리 출력하기
// 나이트 이동은 k번만 가능 - 나이트 이동 횟수에 따라 적용되는 최단거리도 달라지기에 visit도 사용 횟수에 따라 별도로 둬야 함
// 기본적으로 전후좌우로 bfs를 돌리되, 만약 점프 수가 남아있는 경우 나이트로도 bfs를 돌린다
// 전후좌우 bfs에서는 지금 점프 수의 visit, 나이트 bfs에서는 그 다음 점프 수의 visit를 갱신
// 그러면서 거리를 측정해, 목적지에 도달하면 결과를 최소로 갱신시키되 bfs를 끝내지는 않는다
// 가로세로가 평소와 반대로 주어짐에 주의