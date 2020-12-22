// 섬의 개수
// https://www.acmicpc.net/problem/4963

#include <iostream>
#include <vector>
using namespace std;
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int dfs(vector<vector<int>>& board, vector<vector<bool>>& visit, int x, int y, int m, int n) {
	if (board[x][y] == 0 || visit[x][y])
		return 0;
	visit[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= m || yy >= n)
			continue;
		if (!visit[xx][yy] && board[xx][yy] == 1)
			dfs(board, visit, xx, yy, m, n);
	}
	return 1;
}

int main(void) {
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		vector<vector<int>> board(m, vector<int>(n));
		vector<vector<bool>> visit(m, vector<bool>(n));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		int res = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				res += dfs(board, visit, i, j, m, n);
		cout << res << '\n';
	}
}

// 가로, 세로, 대각선으로 이어져있는 섬의 개수는?
// 이번엔 대각선으로도 계산해야 한다