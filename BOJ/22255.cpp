// 호석사우루스
// https://www.acmicpc.net/problem/22255

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct node {
	int len, cnt, x, y;
	bool operator<(const node &a) const {
		if (len != a.len)
			return len > a.len;
		if (cnt != a.cnt)
			return cnt > a.cnt;
		if (x != a.x)
			return x < a.x;
		return y < a.y;
	}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, sx, sy, gx, gy;
	cin >> n >> m >> sx >> sy >> gx >> gy;
	vector<vector<int>> board(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	vector<vector<vector<int>>> dist(3, vector<vector<int>>(n + 1, vector<int>(m + 1, 987654321)));
	priority_queue<node> pq;
	pq.push({ 0, 1, sx, sy });
	dist[1][sx][sy] = 0;
	while (!pq.empty()) {
		node p = pq.top();
		pq.pop();
		if (p.x == gx && p.y == gy)
			continue;
		for (int i = 0; i < 4; i++) {
			if (p.cnt % 3 == 1 && i % 2 == 1)
				continue;
			if (p.cnt % 3 == 2 && i % 2 == 0)
				continue;
			int xx = p.x + dx[i];
			int yy = p.y + dy[i];
			if (xx <= 0 || yy <= 0 || xx > n || yy > m || board[xx][yy] == -1)
				continue;
			int nlen = board[xx][yy] + p.len;
			if (dist[(p.cnt + 1) % 3][xx][yy] > nlen) {
				dist[(p.cnt + 1) % 3][xx][yy] = nlen;
				pq.push({ nlen, p.cnt + 1, xx, yy });
			}
		}
	}
	int res = 987654321;
	for (int i = 0; i < 3; i++)
		res = min(res, dist[i][gx][gy]);
	if (res == 987654321)
		res = -1;
	cout << res << '\n';
}

// 이동 회차에 따라 이동할 수 있는 방향이 다른 공룡을 도달시 충격량이 다른 n*m 보드의 출발점에서 도착점까지 이동시킬 때, 받을 수 있는 최소 충격량은?

// 기본적으로 다익스트라 - 충격량이 곧 거리
// cnt % 3에 따라 상하좌우, 상하, 좌우로만 이동할 수 있음 - 따라서 특정 시점에 못 가는 곳이 생겨 방문한 지점에 다시 돌아와야 최단경로를 얻을 수 있는 경우도 있음
// 따라서 dist 배열은 각 칸에 대해 상하좌우/상하/좌우 이동이 가능할 때를 따로 기록할 것 - 처음에는 상하
// 이를 유의하며 다익스트라 돌려주기 - 이동 횟수도 같이 카운트해주면서, 이동 횟수에 따라 이동 방향 및 dist 갱신 위치 잡기
// 결과적으로 도착지의 dist 중 가장 작은 값이 답