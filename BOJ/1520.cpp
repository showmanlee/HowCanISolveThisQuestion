// 내리막 길
// https://www.acmicpc.net/problem/1520

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
int board[501][501];
int dp[501][501];

int dfs(int x, int y) {
	if (x == n && y == m)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx <= 0 || yy <= 0 || xx > n || yy > m)
			continue;
		if (board[x][y] > board[xx][yy]) {
			dp[x][y] += dfs(xx, yy);
		}
	}
	return dp[x][y];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	memset(dp, -1, sizeof(dp));
	int res = dfs(1, 1);
	cout << res << '\n';
}

// 칸마다 높이가 다른 n*m 보드에서 좌측 상단에서 우측 하단으로 이동하기 위해 내리막길만 탈 때, 가능한 경로 수는?

// dfs 기반으로 접근해야 함 - 내리막길만 타야 하지만 이동할 수 있는 방향이 4방향이기에 단순 dfs로는 시간초과
// 따라서 visit를 dp 기반으로 적용해야 함 - 해당 위치에서 종점까지 갈 수 있는 경로의 수
// dp는 처음에 -1로 초기화하여 !visit의 효과를 준다 - 해당 지점을 방문하면 dp는 최소 0이 됨
// dfs는 시작점부터 시작해 내려가면서 내가 이동할 수 있는 모든 칸의 경로 수를 모두 더해 dp의 값으로 삼고 반환한다
// 만약 dp를 통해 해당 칸에 방문했음이 확인되면 더 이상 방문하지 않고 dp return - 어디에서 들어가든 해당 위치에서 생길 수 있는 경로 수는 같음
// 그리고 마지막칸에 도달했면 1을 반환하여 경로가 시작됨을 알림
// 결과적으로 dp[1][1]의 값이 답이 됨