// 알파벳
// https://www.acmicpc.net/problem/1987

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char board[21][21];
bool visit[26];
int r, c;

int dfs(int x, int y, int count) {
	int ret = -1;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= r || yy >= c)
			continue;
		if (!visit[board[xx][yy] - 'A']) {
			visit[board[xx][yy] - 'A'] = true;
			ret = max(ret, dfs(xx, yy, count + 1));
			visit[board[xx][yy] - 'A'] = false;
		}
	}

	if (ret != -1)
		return ret;
	return count;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];
	visit[board[0][0] - 'A'] = true;
	int res = dfs(0, 0, 1);
	visit[board[0][0] - 'A'] = false;
	cout << res << '\n';
}

// 알파벳이 적힌 보드가 있고, 좌측 상단에서 출발하는 말은 한 번도 밟지 않은 알파벳만을 밟아 한 칸씩 이동해야 할 때, 말이 이동할 수 있는 최대 거리는?
// 탐색한 알파벳을 나타내는 visit 배열을 만들고, dfs로 파고들어가보자
// 일반적인 dfs에서 visit를 칸이 아닌 알파벳 단위로 거는 것