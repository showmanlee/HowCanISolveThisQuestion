// 유닛 이동시키기
// https://www.acmicpc.net/problem/2194

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b, k;
	cin >> n >> m >> a >> b >> k;
	vector<vector<bool>> board(n + 1, vector<bool>(m + 1)), visit(n + 1, vector<bool>(m + 1));
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = true;
	}
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	queue<prr> q;
	q.push({ {sx, sy}, 0 });
	visit[sx][sy] = true;
	int res = -1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int len = q.front().second;
		q.pop();
		if (x == gx && y == gy) {
			res = len;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx <= 0 || yy <= 0 || xx + a - 1 > n || yy + b - 1 > m || board[xx][yy])
				continue;
			bool pass = false;
			for (int j = 0; j < a; j++)
				for (int k = 0; k < b; k++)
					if (board[xx + j][yy + k])
						pass = true;
			if (!pass && !visit[xx][yy]) {
				visit[xx][yy] = true;
				q.push({ {xx, yy}, len + 1 });
			}
		}
	}
	cout << res << '\n';
}

// 장애물이 있는 n*m 보드에서 a*b 크기의 유닛을 출발지에서 도착지까지 이동시킬 때, 장애물에 막히지 않고 이동시킬 수 있는가? 있다면 얼마나 걸리는가?

// 유닛 크기가 1*1이 아닌 bfs 최단거리 탐색
// 맵 이탈 판정을 유닛 크기에 대해서 하고, 유닛이 차지한 모든 칸에 대해 충돌 판정을 돌려주는 것을 빼면 평범한 bfs 최단거리 탐색
// 장애물 및 출발/도착지 입력 방식이 조금 특별함에 주의