// 연구소 2
// https://www.acmicpc.net/problem/17141

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[51][51];
pr virus[11];
int n, m, v, res;

void bfs() {
	vector<vector<int>> visit(n, vector<int>(n, -1));
	queue<pr> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1)
				visit[i][j] = 0;
			else if (board[i][j] == 2) {
				visit[i][j] = 0;
				q.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= n)
				continue;
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				q.push({ xx, yy });
			}
		}
	}
	int ret = 0;
	bool fail = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1)
				fail = true;
			ret = max(ret, visit[i][j]);
		}
	}
	if (fail)
		ret = -1;
	else {
		if (res == -1)
			res = ret;
		else
			res = min(res, ret);
	}	
}

void dfs(int count, int last) {
	if (count == m)
		bfs();
	else {
		for (int i = last; i < v; i++) {
			if (board[virus[i].first][virus[i].second] != 2) {
				board[virus[i].first][virus[i].second] = 2;
				dfs(count + 1, i + 1);
				board[virus[i].first][virus[i].second] = 0;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	v = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int p;
			cin >> p;
			if (p == 2) {
				virus[v++] = { i, j };
				board[i][j] = 0;
			}
			else
				board[i][j] = p;
		}
	}
	res = -1;
	dfs(0, 0);
	cout << res << '\n';
}

// 연구소의 특정 지점에 바이러스를 m(1~10)개 놓을 때, 모든 지역에 바이러스를 퍼뜨릴 수 있는 최소 시간은?
// 바이러스 배치는 브루트포스(dfs), 퍼뜨리는 건 BFS
// 바이러스 자리 수도 바이러스 최대 배치 수도 10개이므로 브루트포스로 접근 가능
// 확실히 전역변수 배치가 재귀/브루트포스를 다룰 때 편하구나