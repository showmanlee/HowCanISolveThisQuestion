// NxM 보드 완주하기
// https://www.acmicpc.net/problem/9944

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m, blank;
char board[31][31];
int res;

void dfs(int x, int y, int count, int left) {
	if (left == 0) {
		res = min(res, count);
		return;
	}
	for (int t = 0; t < 4; t++) {
		int xx = x + dx[t];
		int yy = y + dy[t];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == '*')
			continue;
		int xxx = xx + dx[t];
		int yyy = yy + dy[t];
		while (xxx >= 0 && yyy >= 0 && xxx < n && yyy < m && board[xxx][yyy] == '.') {
			xx = xxx;
			yy = yyy;
			xxx = xx + dx[t];
			yyy = yy + dy[t];
		}
		int l = 0;
		if (dx[t] != 0) {
			for (int i = x + dx[t]; i != xx; i += dx[t]) {
				board[i][yy] = '*';
				l++;
			}
			board[xx][yy] = '*';
		}
		else if (dy[t] != 0) {
			for (int i = y + dy[t]; i != yy; i += dy[t]) {
				board[xx][i] = '*';
				l++;
			}
			board[xx][yy] = '*';
		}
		dfs(xx, yy, count + 1, left - l - 1);
		if (dx[t] != 0) {
			for (int i = x + dx[t]; i != xx; i += dx[t])
				board[i][yy] = '.';
			board[xx][yy] = '.';
		}
		else if (dy[t] != 0) {
			for (int i = y + dy[t]; i != yy; i += dy[t])
				board[xx][i] = '.';
			board[xx][yy] = '.';
		}
	}
}

int main(void) {
	int num = 1;
	while (cin >> n >> m) {
		blank = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				if (board[i][j] == '.')
					blank++;
			}
		}

		res = 987654321;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '.') {
					board[i][j] = '*';
					dfs(i, j, 0, blank - 1);
					board[i][j] = '.';
				}
			}
		}
		if (res == 987654321)
			res = -1;
		cout << "Case " << num << ": " << res << '\n';
		num++;
	}
}

// 장애물이 있는 n*m 보드의 빈 칸 중 하나 공을 넣고, 상하좌우 중 하나의 방향을 선택해 장애물/보드 끝/이미 거친 칸을 만날 때까지 계속 공을 굴리는 과정을 반복한다.
// 이 때 모든 빈 칸을 순회할 수 있는 최소 이동 횟수는?
// 백트래킹과 브루트포스 - 브포 함수에서 각 방향으로 가능한 끝까지 갈 수 있는 좌표를 찾은 다음, 그 좌표까지 방문 표시를 걸고 재귀함수 호출
// 처음 보드를 입력할 때 빈칸 수를 기록하고 재귀함수에서도 남은 빈칸 수와 이동 횟수를 인수로 받다가, 남은 빈칸 수가 0이 되면 결과 갱신 후 탈출
// 30*30 보드지만 이동 경로 수가 100만 개가 넘지 않음이 보장되기에 브포로 접근 가능
// 테케에 별도의 중단점이 정의되지 않음에 주의