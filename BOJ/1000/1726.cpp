// 로봇
// https://www.acmicpc.net/problem/1726

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	int sx, sy, sr, gx, gy, gr;
	cin >> sx >> sy >> sr >> gx >> gy >> gr;
	sr--;
	gr--;
	vector<vector<vector<int>>> visit(n + 1, vector<vector<int>>(m + 1, vector<int>(4, -1)));
	queue<prr> q;
	q.push({ {sx, sy}, sr });
	visit[sx][sy][sr] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int r = q.front().second;
		q.pop();
		if (x == gx && y == gy && r == gr)
			break;
		for (int i = 1; i <= 3; i++) {
			int xx = x + (dx[r] * i);
			int yy = y + (dy[r] * i);
			if (xx <= 0 || yy <= 0 || xx > n || yy > m || board[xx][yy] == 1)
				break;
			if (visit[xx][yy][r] == -1) {
				visit[xx][yy][r] = visit[x][y][r] + 1;
				q.push({ {xx, yy}, r });
			}
		}
		for (int i = 0; i <= 1; i++) {
			int rr = i + (r >= 2 ? 0 : 2);
			if (visit[x][y][rr] == -1) {
				visit[x][y][rr] = visit[x][y][r] + 1;
				q.push({ {x,y}, rr });
			}
		}
	}
	cout << visit[gx][gy][gr] << '\n';
}

// n*m 공간에 앞으로 1~3칸 이동하거나 좌우로 90도 회전할 수 있는 로봇이 있을 때, 도착점에서 특정 방향을 가리키도록 이동하는 경우의 수는?

// 3차원 bfs - x, y, 회전 방향
// 출발 상태와 도착 상태를 받고, 해당 상태에 도달할 때까지 bfs를 돌린다
// 전진 명령의 경우 현재 회전 상태에서 1~3칸을 순차적으로 움직여본다
// 만약 전진 중 벽에 부딪히면 그 이상으로도 나아갈 수 없으니 그 이후는 탐색하지 않기
// 회전 명령의 경우 이동하지 않고 90도씩 회전해본다 - 다만 회전값이 360도 회전 형태가 아닌 동서남북 형태로 주어짐에 주의
// 따라서 나머지 연산 기반이 아닌 조건문 기반으로 다음 회전각을 잡아야 함
// 그런 점만 유의하면 일반적인 bfs 최단 거리 탐색 문제와 동일함