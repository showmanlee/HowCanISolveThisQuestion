// 시루의 백화점 구경
// https://www.acmicpc.net/problem/25307

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> board(n, vector<int>(m)), visit(n, vector<int>(m, -1));
	queue<pr> q;
	queue<prr> qq;
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 3) {
				board[i][j] = 1;
				visit[i][j] = -2;
				qq.push({{i, j}, k});
			} else if (board[i][j] == 4) {
				sx = i;
				sy = j;
			}
		}
	}
	
	while (!qq.empty()) {
		int x = qq.front().first.first;
		int y = qq.front().first.second;
		int t = qq.front().second;
		qq.pop();
		board[x][y] = 1;
		if (t > 0) {
			t--;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
					continue;
				}
				if (visit[xx][yy] != -2) {
					visit[xx][yy] = -2;
					qq.push({{xx, yy}, t});
				}
			}
		}
	}

	q.push({sx, sy});
	visit[sx][sy] = 0;
	int res = -1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (board[x][y] == 2) {
			res = visit[x][y];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == 1) {
				continue;
			}
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				q.push({xx, yy});
			}
		}
	}
	cout << res << '\n';
}

// 기둥이 있는 n*m 공간에서 출발점에서 벤치까지 이동할 때, 마네킹이 있는 곳 반경 k칸에 접근하지 않고 벤치까지 이동하는 최단 경로는?

// 벤치가 없을 수도 있고, k가 0일 수도 있고 그럼
// k가 0인 경우 마네킹이 있는 곳만 접근불가, 그 이상인 경우 맨해튼 거리로 k 이하인 곳 접근 불가 - 쉽게 말해 주변 영역이 기둥이 된다 생각하면 됨
// 이를 이용해 마네킹 기둥 영역 확장을 위한 bfs를 돌리고, 벤치 최단거리 측정을 위한 bfs를 돌려준다