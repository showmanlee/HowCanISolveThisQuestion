// 방탈출
// https://www.acmicpc.net/problem/23352

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0, dist = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0) {
				vector<vector<int>> visit(n, vector<int>(m, -1));
				queue<pr> q;
				q.push({ i, j });
				visit[i][j] = 0;
				if (dist == 0) {
					res = max(res, board[i][j] * 2);
				}
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == 0) {
							continue;
						}
						if (visit[xx][yy] == -1) {
							visit[xx][yy] = visit[x][y] + 1;
							if (visit[xx][yy] > dist) {
								dist = visit[xx][yy];
								res = 0;
							}
							if (visit[xx][yy] == dist) {
								res = max(res, board[i][j] + board[xx][yy]);
							}
							q.push({ xx, yy });
						}
					}
				}
			}
		}
	}
	cout << res << '\n';
}

// 각 칸에 숫자가 적힌 n*m 보드의 0이 아닌 두 수를 최단거리로 이었을 때 가장 먼 거리에 있는 두 숫자의 합의 최댓값 구하기

// 모든 칸에서 시작해 bfs로 칸 거리를 구하며 현재까지 가장 먼 거리일 경우 두 수의 합의 최댓값을 구해 결과를 찾는다
// 최대 50*50이므로 bfs를 50*50번 돌려도 상관은 없음
// 다만 어떤 쪽에서 접근하든 결과는 같기에... 이미 발견한 쌍은 찾지 않도록 하면 탐색을 더 아낄 수 있을까