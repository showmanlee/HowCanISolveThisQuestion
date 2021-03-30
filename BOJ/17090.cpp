// 미로 탈출하기
// https://www.acmicpc.net/problem/17090

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int n, m;
char board[501][501];
bool visit[501][501];
bool outable[501][501];

bool dfs(int x, int y) {
	visit[x][y] = true;
	int xx = x, yy = y;
	if (board[x][y] == 'D')
		xx++;
	else if (board[x][y] == 'U')
		xx--;
	else if (board[x][y] == 'R')
		yy++;
	else if (board[x][y] == 'L')
		yy--;
	if (xx < 0 || yy < 0 || xx >= n || yy >= m)
		outable[x][y] = true;
	else {
		if (visit[xx][yy])
			outable[x][y] = outable[xx][yy];
		else
			outable[x][y] = dfs(xx, yy);
	}
	return outable[x][y];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visit[i][j])
				dfs(i, j);

	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (outable[i][j])
				res++;
	cout << res << '\n';
}

// 각 칸에 이동하는 방향이 적힌 n*m 보드에서 보드 바깥으로 나갈 수 있는 칸의 수는?
// DFS로 접근 - 다만 이번에는 칸 당 탐색 방향이 하나로 정해진
// 중복 탐색을 막기 위해 visit와 함께 해당 칸에서의 탈출 여부를 표시하는 outable 배열을 생성 - DP
// visit는 해당 칸이 탐색될 때 체크하고, outable은 해당 칸에서 탈출이 가능할 때 체크
// 최초로 탈출 가능한 칸은 그냥 체크하고, 그 칸으로 향하던 경로(스택)의 칸들은 dfs 함수 리턴으로 체크해주기
// 경로 바깥에 있던 칸이 visit가 체크된 칸(= outable이 판정된 칸)을 탐색하려 하는 경우 dfs 함수 호출 대신 outable에 저장된 값을 통해 outable 기록
// 이 과정을 탐색하지 않는 모든 칸을 대상으로 반복 후 outable[i][j] = true인 칸을 세서 결과 출력하기