// 빵집
// https://www.acmicpc.net/problem/3109

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[3] = { -1, 0, 1 };

int r, c;
char board[10001][501];
bool visit[10001][501];

bool dfs(int x, int y) {
	visit[x][y] = true;
	if (y == c - 1)
		return true;
	for (int i = 0; i < 3; i++) {
		int xx = x + dx[i];
		int yy = y + 1;
		if (xx < 0 || xx >= r)
			continue;
		if (board[xx][yy] == '.' && !visit[xx][yy]) {
			bool ret = dfs(xx, yy);
			if (ret)
				return true;
		}
	}
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];
	int res = 0;
	for (int i = 0; i < r; i++)
		res += (dfs(i, 0) ? 1 : 0);
	cout << res << '\n';
}

// r*c 보드의 좌측 가스관에서 우측 빵집으로 가스를 끌어오기 위해 우상/우/우하 방향의 파이프를 놓을 때, 놓을 수 있는 파이프라인의 최대 개수는?

// 파이프라인을 많이 놓기 위해서는 파이프를 한쪽으로 몰아넣어야 함 - 가능한 한 한쪽 방향(여기서는 상단)으로 파이프 방향 유도하기
// 예제의 경우에도 파이프라인을 최대한 위에서부터 놓기 시작해 위쪽으로 몰아넣어도 같은 결과가 나옴 - 즉, 그리디 원리로 유도 가능
// 파이프 설치는 단방향으로 진행되는 dfs로 - 탐색 순서는 상단 먼저
// 만약 무사히 우측까지 파이프를 놓았다면 dfs 함수에서 true 판정 - 이후 재귀적으로 true를 반환함으로서 더 이상 탐색하지 않도록 함
// dfs 함수 최초 호출은 매 행마다 실행 - 벽들이 없는 경우, 최대로 놓을 수 있는 파이프 수는 r개
// 결과적으로 dfs + 그리디 문제