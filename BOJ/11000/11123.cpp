// 양 한마리... 양 두마리...
// https://www.acmicpc.net/problem/11123

#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(vector<vector<bool>>& board, vector<vector<bool>>& visit, int x, int y, int h, int w) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= h || yy >= w)
			continue;
		if (board[xx][yy] && !visit[xx][yy])
			dfs(board, visit, xx, yy, h, w);
	}
}

int main(void) {
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		int h, w;
		cin >> h >> w;
		vector<vector<bool>> board(h, vector<bool>(w)), visit(h, vector<bool>(w));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				char c;
				cin >> c;
				board[i][j] = c == '#';
			}
		int res = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				if (board[i][j] && !visit[i][j]) {
					res++;
					dfs(board, visit, i, j, h, w);
				}
			}
		cout << res << '\n';
	}
}

// 양이 있는 덩어리의 수는?
// DFS로 visit 넣어주며 덩어리 찾기