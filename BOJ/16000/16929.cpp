// Two Dots
// https://www.acmicpc.net/problem/16929

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

char board[51][51];
int visit[51][51];
int n, m;
int res;

void dfs(int x, int y, int len) {
	if (visit[x][y] == 2) {
		if (len >= 4)
			res = max(res, len);
		return;
	}
	visit[x][y] = 1;
	len++;
	if (len == 1)
		visit[x][y] = 2;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)
			continue;
		if (board[x][y] == board[xx][yy]) {
			if (visit[xx][yy] == 0)
				dfs(xx, yy, len);
			if (visit[xx][yy] == 2 && len >= 4)
				dfs(xx, yy, len);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visit, 0, sizeof(visit));
			dfs(i, j, 0);
		}
	}
	cout << (res >= 4 ? "Yes" : "No") << '\n';
}

// 각 칸이 알파벳이 있는 n*m 보드에서 같은 알파벳이 상하좌우로 이어진 길이 4 이상의 사이클이 존재하는가?

// 사이클 길이 판별은 dfs 기반으로 접근해야 함
// 보드를 받고, 모든 칸에 대해 dfs를 돌려본다 - visit 배열은 매 탐색 시작마다 초기화
// dfs 함수는 x, y, 길이를 매개변수로 받음
// 만약 처음으로 들어가는 곳이라면 해당 칸의 visit를 2로 설정하여 종료 지점을 알 수 있도록 설정 - 그렇지 않다면 1
// dfs를 돌면서 길이를 누적시키고, 만약 visit가 2인 칸에 도달했는데 길이가 4 이상 쌓였다면 사이클 존재 판정하기