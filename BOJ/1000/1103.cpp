// 게임
// https://www.acmicpc.net/problem/1103

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
char board[51][51];
bool visit[51][51];
int dp[51][51];
bool fail;

int dfs(int x, int y) {
	if (visit[x][y] || fail) {
		fail = true;
		return 0;
	}
	if (dp[x][y] != -1)
		return dp[x][y];

	visit[x][y] = true;
	dp[x][y] = 0;
	int jmp = board[x][y] - '0';
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i] * jmp;
		int yy = y + dy[i] * jmp;
		if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == 'H')
			dp[x][y] = max(dp[x][y], 1);
		else
			dp[x][y] = max(dp[x][y], dfs(xx, yy) + 1);
	}
	visit[x][y] = false;
	return dp[x][y];
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	fail = false;
	int res = dfs(0, 0);
	if (fail)
		res = -1;
	cout << res << '\n';
}

// 각 칸에 1~9, 그리고 구멍(H)이 있는 게임 판 좌측 상단에 동전을 놓고, 상하좌우로 칸에 적힌 수만큼 동전을 이동하는 게임을 하려고 한다.
// 이동한 결과가 보드 밖이거나 구멍이면 게임이 종료된다고 할 때, 가능한 최대 이동 수는(사이클이 발생할 수 있음)?

// 단순히 칸을 순회하며 최대 이동 수를 갱신하는 dfs 문제처럼 보이나, 단순히 res를 단일 변수로 관리하면 안 됨
// res 변수가 아닌 DP를 접목해야 한다 - 현재 칸에서 출발하는 최대 이동 횟수를 기록하는 dp 배열 (초기화는 -1)
// 매 칸 진입 시 dp[x][y]는 0으로 초기화되고, 순회 상황에 따라 dp[x][y]를 갱신시킨 후 반환한다.
// 다음 칸을 탐색할 때마다 dp[x][y]를 max(dp[x][y], dfs(xx, yy) + 1)로 갱신 - 저쪽 칸의 최대 이동 수 + 1(0일 경우 우리 칸의 이동 횟수는 1이 됨)
// 이때 게임이 끝나는 '칸'에 도달한다고 해도 dp[x][y]를 갱신하는 작업이 필요함 - 어쨌든 그 '칸'에서는 최대 이동 수가 0이 되고, 그렇게 우리 칸의 이동 횟수가 1이 되기 때문
// 탐색하려는 칸이 만약 경로 상에서 해당 칸을 거쳤다면(visit[x][y]) fail(-1) 판정
// 만약 경로 상에서 해당 칸을 거치지 않았지만 이미 dp 기록이 있는 경우(dp[x][y] != -1) dp[x][y] 반환 - 어차피 경우의 수는 변하지 않음
// 출발점이 [0][0]이기에, 결과는 dp[0][0]이 됨(fail일 경우 -1)

// BOJ 530문제 돌파 - 하지만 아직도 상상력이 부족해
// 반드시 플레를 찍고 말겠어