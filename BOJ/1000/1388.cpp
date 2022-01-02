// 바닥 장식
// https://www.acmicpc.net/problem/1388

#include <iostream>
#include <vector>
using namespace std;

int n, m;
char board[101][101];
bool visit[101][101];
int res;

void dfs(int x, int y) {
	visit[x][y] = true;
	if (board[x][y] == '-') {
		if (y + 1 >= m || board[x][y + 1] != '-') {
			res++;
			return;
		}
		else 
			dfs(x, y + 1);
	}
	else {
		if (x + 1 >= n || board[x + 1][y] != '|') {
			res++;
			return;
		}
		else
			dfs(x + 1, y);
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visit[i][j])
				dfs(i, j);
	cout << res << '\n';
}

// 가로/세로 나무판자가 바닥에 놓였을 때, 필요한 판자의 수는?
// -이 가로로 이어졌거나, |가 세로로 이어진 경우 한 장으로 계산
// dfs로 접근 - -와 |를 따라가다가 다른 걸 만났거나 보드 바깥으로 가면 개수 추가