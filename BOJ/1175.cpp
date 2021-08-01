// 배달
// https://www.acmicpc.net/problem/1175

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> prrr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int sx, sy;
	vector<vector<char>> board(n, vector<char>(m));
	vector<pr> goal(2);
	int gi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if (board[i][j] == 'C') {
				goal[gi].first = i;
				goal[gi].second = j;
				gi++;
			}
		}
	}
	vector<vector<vector<vector<int>>>> visit(n, vector<vector<vector<int>>>(m, vector<vector<int>>(5, vector<int>(4, -1))));
	queue<prrr> q;
	q.push({ {sx, sy}, {4, 0} });
	visit[sx][sy][4][0] = 0;
	int res = -1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (cnt == 3) {
			res = visit[x][y][dir][cnt];
			break;
		}
		for (int i = 0; i < 4; i++) {
			if (i == dir)
				continue;
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == '#')
				continue;
			if (visit[xx][yy][i][cnt] == -1) {
				int ncnt = cnt;
				for (int j = 0; j < 2; j++) {
					if (goal[j].first == xx && goal[j].second == yy && (ncnt >> j) % 2 == 0) {
						ncnt += 1 << j;
					}
				}
				visit[xx][yy][i][ncnt] = visit[x][y][dir][cnt] + 1;
				q.push({ {xx, yy}, {i, ncnt} });
			}
		}
	}
	cout << res << '\n';
}

// n*m 공간에 2개의 배달 지점이 있고, 배달원은 상하좌우로 움직이되 이전에 움직인 방향으로는 이동할 수 없을 때, 두 지점에 모두 배달하는데 걸리는 최소 시간은?

// bfs - 이전 이동 방향에 따라 이동 가능 방향이 갈리는 등의 경우 visit를 한차원 더 키워서 관리해야 함
// 게다가 여기서는 한번 밟은 곳을 다시 밞으면 안 된다는 제한 사항은 없음 - 물론 밟은 땅을 다시 밟으면 최단거리가 될 수 없음은 자명함
// 그런데 어떤 배달 지점을 찍으면 새로운 경로가 열리는 것으로 볼 수 있음 - 반대로 새로운 배달 지점을 찍기 전까지는 밟은 땅을 다시 밟았을 때 비효율적임
// 추가로 배달 지점이 모두 독립적이기에, visit에서도 독립적으로 관리해주어야 함 - 두 지점을 모두 밟으면 미션 완료
// 따라서 bfs visit는 4차원으로 관리 - x, y, 이전 이동 방향, 밟은 배달 지점(비트)
// 이전 이동 방향의 경우 초반에는 무뱡향으로 표시 - 따라서 이동 방향 차원 폭은 5가 되어야 함(상하좌우'무')

// 우선 보드를 받으며 출발 지점을 기록한다 - 도착 지점의 경우 배열 형태로 기록하여 각 지점에 인덱스를 부여한다
// 이후 출발 지점부터 bfs를 돌리는데, 이전 이동 방향은 무방향, 밟은 지점 수는 0으로 하여 시작
// bfs 탐색 중 이전 이동 방향과 같은 방향으로 갈 경우, 그리고 벽을 만난 경우는 탐색 생략
// 그리고 도착지를 밟은 경우 밟은 배달 지점을 새로 기록해준 후 큐에 삽입
// 그렇게 탐색하다 밟은 배달 지점이 11이 되면 그때까지의 길이 출력하고 탐색 종료