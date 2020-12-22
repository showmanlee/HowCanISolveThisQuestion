// 영역 구하기
// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(vector<vector<bool>>& board, vector<vector<bool>>& visit, int x, int y, int n, int m) {
	if (board[x][y] || visit[x][y])
		return 0;
	visit[x][y] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)
			continue;
		if (!board[xx][yy] && !visit[xx][yy])
			ret += dfs(board, visit, xx, yy, n, m);
	}
	return ret;
}

int main(void) {
	int m, n, k;
	cin >> m >> n >> k;
	vector<vector<bool>> board(n, vector<bool>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int x = a; x < c; x++)
			for (int y = b; y < d; y++)
				board[x][y] = true;
	}
	vector<int> sizes;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int res = dfs(board, visit, i, j, n, m);
			if (res > 0)
				sizes.push_back(res);
		}
	sort(sizes.begin(), sizes.end());
	cout << sizes.size() << '\n';
	for (int i : sizes)
		cout << i << ' ';
	cout << '\n';
}

// 모눈종이에 직사각형을 그린 후 남은 공간의 개수와 그 크기는?
// dfs로 영역들을 구하고 정렬 필요