// 아기 상어 2
// https://www.acmicpc.net/problem/17086

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<int>> visit(n, vector<int>(m, -1));
	queue<pr> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i, j });
				visit[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				q.push({ xx, yy });
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res = max(res, visit[i][j]);
	cout << res << '\n';
}

// n*m 공간에서 아기 상어 간에 확보한 최대 안전 거리는?
// 안전 거리는 두 상어가 서로를 향해 가로/세로/대각선으로 한칸씩 올 때 걸리는 시간(의 최대)
// 따라서 이번엔 visit 배열을 정수 형태로 관리 - 상어 있는 칸을 0으로 시작하여 매 칸에 상어가 도달할 수 있는 시간을 기록한다
// 그리고 그 visit 배열의 최댓값이 결과
// 아기 상어 1과 관계없음에 주의