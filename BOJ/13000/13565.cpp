// 침투
// https://www.acmicpc.net/problem/13565

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(vector<vector<bool>>& board, vector<vector<bool>>& visit, int x, int y, int n, int m) {
	if (board[x][y])
		return;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)
			continue;
		if (!board[xx][yy] && !visit[xx][yy])
			dfs(board, visit, xx, yy, n, m);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> board(n, vector<bool>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			board[i][j] = c == '1';
		}
	}
	for (int i = 0; i < m; i++)
		dfs(board, visit, 0, i, n, m);

	bool res = false;
	for (int i = 0; i < m; i++)
		if (visit[n - 1][i])
			res = true;
	cout << (res ? "YES\n" : "NO\n");
}

// 맨 윗줄에서 흘린 전기가 맨 아랫줄까지 흐르는가?
// dfs로 풀기