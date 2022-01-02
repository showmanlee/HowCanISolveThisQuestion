// 안전 영역
// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(vector<vector<bool>>& flood, vector<vector<bool>>& visit, int x, int y, int n) {
	if (visit[x][y] || flood[x][y])
		return 0;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= n)
			continue;
		if (!visit[xx][yy] && !flood[xx][yy])
			dfs(flood, visit, xx, yy, n);
	}
	return 1;
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	int max = 1, min = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] < min)
				min = board[i][j];
			if (board[i][j] > max)
				max = board[i][j];
		}
	}
	int res = 0;
	for (int f = min - 1; f <= max; f++) {
		vector<vector<bool>> flood(n, vector<bool>(n));
		vector<vector<bool>> visit(n, vector<bool>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] <= f)
					flood[i][j] = true;
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				count += dfs(flood, visit, i, j, n);
		if (count > res)
			res = count;
	}
	cout << res << '\n';
}

// 칸마다 높이가 다른 땅에서 장마 양에 따라 물에 잠기지 않는 안전 영역의 최대 개수는?
// 최소부터 최대까지 비를 내려보고 공간 나오는 최대를 구할까
// 물에 잠기지 않는 경우(최소 높이보다 비가 적게 내리는 경우)가 있을 수 있기에 최소 - 1부터 비를 뿌려야 함 - or 최소 결과값을 1로 맞추거나