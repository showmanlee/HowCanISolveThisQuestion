// 보물섬
// https://www.acmicpc.net/problem/2589

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

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<pr> lands;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L')
				lands.push_back({ i, j });
		}
	}
	int res = 0;
	for (int a = 0; a < lands.size() - 1; a++) {
		int sx = lands[a].first, sy = lands[a].second;
		vector<vector<bool>> visit(n, vector<bool>(m));
		queue<prr> q;
		visit[sx][sy] = true;
		q.push({ {sx, sy}, 0 });
		int r = 0;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int d = q.front().second;
			q.pop();
			r = max(r, d);
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy])
					continue;
				if (board[xx][yy] == 'L') {
					visit[xx][yy] = true;
					q.push({ {xx, yy}, d + 1 });
				}
			}
		}
		res = max(res, r);
	}
	cout << res << '\n';
}

// 땅과 바다가 섞여있는 n*m 보드에서 땅의 칸과 칸 사이의 최단거리가 가장 긴 지점에 보물이 나누어 묻혀있을 때, 보물이 나누어 묻힌 곳 사이의 거리는?

// 그러니까, 땅과 땅 사이의 최단거리가 가장 먼 곳의 거리를 묻는 문제
// bfs에서 가장 처음 만나는 곳이 가장 가까운 지점이고, 가장 마지막으로 만나는 곳이 가장 먼 지점이다
// 이 원리를 이용해 모든 땅들을 순회하며 해당 위치에서 도달할 수 있는 가장 먼 지점의 거리를 알 수 있음
// 마침 보드가 최대 50*50=2500칸이 있을 수 있기에 전체 탐색 가능

// 보드를 입력받으며, 땅의 위치들을 저장해두기
// 이후 저장한 땅을 하나씩 순회하며 해당 위치를 시작점으로 한 bfs를 돌려 거기서 얻을 수 있는 가장 먼 거리를 찾고, 이를 결과값에 비교하여 갱신하기
// 어디인가를 묻는 것이 아닌 얼마나 되는가를 묻기에 max로도 처리 가능