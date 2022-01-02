// 쉬운 최단거리
// https://www.acmicpc.net/problem/14940

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> visit(n, vector<int>(m));
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> visit[i][j];
			if (visit[i][j] == 1)
				visit[i][j] = -1;
			else if (visit[i][j] == 2) {
				sx = i;
				sy = j;
				visit[i][j] = 0;
			}
		}
	}
	queue<pr> q;
	q.push({ sx, sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				q.push({ xx, yy });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << visit[i][j] << ' ';
		cout << '\n';
	}
}

// n*m 보드에 벽이 아닌 어떤 지점에서 목적지까지 가는 최단거리 출력하기

// 어떤 지점에서 목적지까지 가는 최단거리 = 목적지에서 어떤 지점까지 가는 최단거리
// 따라서 bfs로 목적지부터 보드 전체를 순회하며 도달한 가장 빠른 거리를 기록한다