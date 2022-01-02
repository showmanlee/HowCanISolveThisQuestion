// 미로 탈출
// https://www.acmicpc.net/problem/14923

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

	int n, m, sx, sy, gx, gy;
	cin >> n >> m >> sx >> sy >> gx >> gy;
	vector<vector<int>> board(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	vector<vector<vector<int>>> visit(2, vector<vector<int>>(n + 1, vector<int>(m + 1, 987654321)));
	queue<prr> q;
	q.push({ {sx, sy}, 0 });
	visit[0][sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int broke = q.front().second;
		q.pop();
		if (x == gx && y == gy)
			continue;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx <= 0 || yy <= 0 || xx > n || yy > m)
				continue;
			if (broke == 0 && board[xx][yy] == 1) {
				if (visit[1][xx][yy] == 987654321) {
					visit[1][xx][yy] = visit[broke][x][y] + 1;
					q.push({ {xx, yy}, 1 });
				}
			}
			if (board[xx][yy] == 0) {
				if (visit[broke][xx][yy] == 987654321) {
					visit[broke][xx][yy] = visit[broke][x][y] + 1;
					q.push({ {xx, yy}, broke });
				}
			}
		}
	}
	int res = min(visit[0][gx][gy], visit[1][gx][gy]);
	if (res == 987654321)
		res = -1;
	cout << res << '\n';
}

// n*m 미로에서 출발점에서 도착점까지 이동하기 위해 벽을 하나 뚫을 수 있는 경우 도달하는데 덜리는 최소 시간은?

// 벽 부수고 이동하기와 같은 원리 - 벽 파괴 여부를 기억하는 bfs
// 보드와 출발점, 도착점을 받고 출발점에서부터 bfs 시작
// 여기서 bfs는 현재 좌표와 함께 벽 파괴 여부를 함께 다루고, 이에 맞춰 visit 배열 역시 3차원으로 설계
// bfs에서 이동하며 이동하려는 칸의 상태를 확인
// 만약 빈칸이라면 평소대로 visit에 마킹 후 이동
// 만약 벽이라면 벽 파괴 여부를 보고, 파괴되지 않았다면 파괴됐다고 표시하고 벽 파괴 visit에 마킹 후 이동 - 이미 파괴한 상태라면 이동하지 않음
// 도착점에 도달하거나 탐색이 끝나면 두 도착점 visit를 보고, 더 작은 값 출력하기 - 둘 다 갱신되지 않았다면 -1 출력