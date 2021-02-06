// 그림
// https://www.acmicpc.net/problem/1926

#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(vector<vector<int>>& board, vector<vector<bool>>& visit, int x, int y, int n, int m) {
	int ret = 1;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)
			continue;
		if (board[xx][yy] && !visit[xx][yy])
			ret += dfs(board, visit, xx, yy, n, m);
	}
	return ret;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int count = 0, max = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] && !visit[i][j]) {
				count++;
				int p = dfs(board, visit, i, j, n, m);
				if (p > max)
					max = p;
			}
	cout << count << '\n' << max << '\n';
}

// 영역의 개수와 가장 큰 영역의 크기는?
// dfs로 풀어가기
// 발견 안한 덩어리 발견시 카운트 늘리고, 함수 안에서 영역 체크