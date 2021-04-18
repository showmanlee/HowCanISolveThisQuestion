// 점프
// https://www.acmicpc.net/problem/1890

#include <iostream>
#include <vector>
using namespace std;

int n;
long long board[101][101];
long long dp[101][101];

long long dfs(int x, int y) {
	if (x >= n || y >= n)
		return 0;
	if (x == n - 1 && y == n - 1)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;
	dp[x][y] += dfs(x + board[x][y], y) + dfs(x, y + board[x][y]);
	return dp[x][y];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}
	dfs(0, 0);
	cout << dp[0][0] << '\n';
}

// n*n 보드에서 좌측 상단부터 우측 하단까지 이동하는데, 반드시 칸에 적힌 숫자만큼 우측 또는 하단으로만 이동할 수 있다. 이때 가능한 경로 수는?
// bfs를 떠올릴 수도 있으나, 메모리가 적고 경로 수가 long long 범위까지 나올 수 있음 - bfs로 못 품
// 그럼 뭐겠습니까 - dp지요

// 여러 갈래로 나눠지니만큼 재귀함수를 이용한 dp로 접근 - 각 칸에서 해당 칸에서 시작한 경로가 몇 개인지 저장
// 매개변수로 받은 좌표에서, 영역을 벗어나면 0, 도착지라면 1을 반환 - 도착지에서 시작하면 당연히 1
// 만약 이미 기록된 상태(방문한 상태)라면 기록된 것을 반환
// 이후 해당 칸에서 오른쪽으로 간 경우와 아래로 간 경우를 재귀함수로 호출하여 반환값을 현재 칸에 기록 후 반환
// 이렇게 하면 dfs로 한 번씩 갈 것을 한꺼번에 갈 수 있어서 좋지요