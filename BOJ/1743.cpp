// 음식물 피하기
// https://www.acmicpc.net/problem/1743

#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(vector<vector<bool>>& foods, vector<vector<bool>>& visit, int x, int y, int n, int m) {
	visit[x][y] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)
			continue;
		if (!visit[xx][yy] && foods[xx][yy])
			ret += dfs(foods, visit, xx, yy, n, m);
	}
	return ret;
}

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<bool>> foods(n, vector<bool>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		foods[x - 1][y - 1] = true;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && foods[i][j]) {
				int p = dfs(foods, visit, i, j, n, m);
				if (p > max)
					max = p;
			}
		}
	}
	cout << max << '\n';
}

// 2차원 공간에 떨어진 음식물 중 가장 큰 거 찾기
// dfs로 가장 큰 공간 찾기