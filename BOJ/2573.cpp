// 빙산
// https://www.acmicpc.net/problem/2573

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int res = 0;
	while (true) {
		vector<vector<bool>> visit(n, vector<bool>(m));
		queue<pr> q;
		int p = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 0 && !visit[i][j]) {
					p++;
					q.push({ i, j });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++) {
							int xx = x + dx[k];
							int yy = y + dy[k];
							if (xx < 0 || yy < 0 || xx >= n || yy >= m)
								continue;
							if (!visit[xx][yy] && board[xx][yy] != 0) {
								visit[xx][yy] = true;
								q.push({ xx, yy });
							}
						}
					}
				}
			}
		}
		if (p != 1) {
			if (p == 0)
				res = 0;
			break;
		}
		res++;
		vector<vector<int>> temp(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				temp[i][j] = board[i][j];
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (board[i][j] != 0) {
					int t = 0;
					for (int k = 0; k < 4; k++) {
						int xx = i + dx[k];
						int yy = j + dy[k];
						if (temp[xx][yy] == 0)
							t++;
					}
					board[i][j] -= t;
					if (board[i][j] < 0)
						board[i][j] = 0;
				}
			}
		}
	}
	cout << res << '\n';
}

// 빙산이 주변 바닷물의 수만큼 매년 녹을 때, 빙산이 두 덩어리 이상이 되는 시점은?
// BFS로 덩어리 수 체크하고, 빙산이 있을 수 전체 칸(상하좌우 한 줄씩 제외)에 대해 녹이는 작업을 해야 함
// 녹이는 작업 중 먼저 작업된 얼음에 의해 잘못 녹을 수도 있으니, 주변 바닷물 여부 체크는 별도로 복사한 배열에서 가져오기
// 덩어리가 갈라지지 않고 다 녹으면(덩어리 수가 0이 되면) 결과값도 0이 되어야 함에 주의