// 숫자 정사각형
// https://www.acmicpc.net/problem/1051

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
char board[50][50];
int res;

int bfs(int x, int y) {
	int ret = 1;
	for (int i = 1; ; i++) {
		int nx = x + i;
		int ny = y + i;
		if (nx >= n || ny >= m)
			break;
		if (board[x][y] == board[nx][ny] && board[x][y] == board[x][ny] && board[x][y] == board[nx][y])
			ret = (i + 1) * (i + 1);
	}
	return ret;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res = max(res, bfs(i, j));
	cout << res << '\n';
}

// 숫자가 적힌 직사각형에서 네 꼭짓점의 쓰인 수가 모두 같은 정사각형의 최대 크기는?
// 꼭짓점만 보면 됨 - 브루트포스로 크기 키워나가기
// 출발점 잡고, 범위 벗어나기 전까지 크기 키우면서 값 갱신하기
// 중단 조건은 크기를 벗어났을 때만 - 중간에 틀려도 그 앞에게 맞을 수도 있음