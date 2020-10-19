// 유기농 배추
// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(vector<vector<bool>> &cab, vector<vector<bool>> &visit, int x, int y, int n, int m) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)
			continue;
		if (cab[xx][yy] && !visit[xx][yy])
			dfs(cab, visit, xx, yy, n, m);
	}
}

int main(void) {
	int c;
	cin >> c;
	for (int p = 0; p < c; p++) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<bool>> cab(n, vector<bool>(m));
		vector<vector<bool>> visit(n, vector<bool>(m));
		for (int q = 0; q < k; q++) {
			int x, y;
			cin >> x >> y;
			cab[x][y] = true;
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cab[i][j] && !visit[i][j]) {
					count++;
					dfs(cab, visit, i, j, n, m);
				}
			}
		}
		cout << count << '\n';
	}
}

// n * m에서 영역 개수 구하는 문제
// DFS의 기본 문제