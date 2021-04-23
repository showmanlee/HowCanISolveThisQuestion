// 숫자판 점프
// https://www.acmicpc.net/problem/2210

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool visit[1000001];
int board[5][5];

void dfs(int x, int y, int cnt, string s) {
	if (cnt == 6) {
		visit[stoi(s)] = true;
		return;
	}
	s += (board[x][y] + '0');
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= 5 || yy >= 5)
			continue;
		dfs(xx, yy, cnt + 1, s);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			dfs(i, j, 0, "");
	int res = 0;
	for (int i = 0; i < 1000000; i++)
		if (visit[i])
			res++;
	cout << res << '\n';
}

// 숫자가 적힌 5*5 보드에서 임의의 위치에서 시작해 상하좌우로 5번 이동해 만들 수 있는 수의 개수는?

// 브루트포스 - 중복이 가능한 재귀를 덧붙인
// 각 칸에서 시작하여 가능한 6자리 경로를 dfs로 탐색한 후, 완성되면 해당 숫자가 완성되었는지 표시하는 배열에 표시한다
// 이후 해당 배열을 0~999999까지 순회하며 완성된 수를 세면 됨