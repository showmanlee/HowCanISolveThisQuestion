// 욕심쟁이 판다
// https://www.acmicpc.net/problem/1937

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n;
int board[501][501];
int dp[501][501];

void dfs(int x, int y) {
	if (dp[x][y] != 0)
		return;
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= n)
			continue;
		if (board[x][y] < board[xx][yy]) {
			dfs(xx, yy);
			dp[x][y] = max(dp[x][y], dp[xx][yy] + 1);
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dfs(i, j);
			if (res < dp[i][j])
				res = dp[i][j];
		}
	}
	cout << res << '\n';
}

// n*n 대나무숲에서 판다는 해당 위치의 대나무를 모두 먹고 다른 곳으로 이동한다. 임의의 칸에 판다를 놓을 때, 최대로 살 수 있는 일 수는?
// 최대 500*500이라 매 칸 dfs를 돌려 최대 거리를 측정한다면 시간 초과 가능성 높음 - dp 도입
// dp에는 각 칸에서 최대로 살 수 있는 날짜를 기록 - 최소는 1(어디에 둬도 하루는 살 수 있음)
// dp는 visit의 역할도 수행 - 해당 위치에서 살 수 있는 최다 일 수를 기록하기 때문에 이미 결과가 나온 칸으로 들어간 경우 그 칸에 적힌 일 수 + 1을 사는 것이 보장됨
// 따라서 dp 갱신은 dfs(xx, yy) 후 max(dp[x][y], dp[xx][yy] + 1)로 처리
// 결과는 dp의 최댓값이 됨