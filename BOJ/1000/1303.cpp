// 전쟁 - 전투
// https://www.acmicpc.net/problem/1303

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(vector<vector<char>>& board, vector<vector<bool>>& visit, int m, int n, int x, int y) {
	visit[x][y] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= m || yy >= n)
			continue;
		if (!visit[xx][yy] && board[x][y] == board[xx][yy])
			ret += dfs(board, visit, m, n, xx, yy);
	}
	return ret;
}

int main(void) {
	int n, m;
	int b = 0, w = 0;
	cin >> n >> m;
	vector<vector<char>> board(m, vector<char>(n));
	vector<vector<bool>> visit(m, vector<bool>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			int p = 0;
			if (!visit[i][j])
				p = dfs(board, visit, m, n, i, j);
			if (board[i][j] == 'B')
				b += p * p;
			else
				w += p * p;
		}
	cout << w << ' ' << b << '\n';
}

// 우리편(W)와 쟤네편(B)의 위력(병사끼리 뭉친 덩어리 ^ 2의 합) 표시하기
// 양쪽의 개수를 카운팅하는 DFS 문제