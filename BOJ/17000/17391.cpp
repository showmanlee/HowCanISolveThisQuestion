// 무한부스터
// https://www.acmicpc.net/problem/17391

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	vector<vector<int>> visit(n, vector<int>(m, -1));
	queue<pr> q;
	q.push({ 0, 0 });
	visit[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1)
			break;
		int cnt = board[x][y];
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= cnt; j++) {
				int xx = x + dx[i] * j;
				int yy = y + dy[i] * j;
				if (xx < 0 || yy < 0 || xx >= n || yy >= m)
					continue;
				if (visit[xx][yy] == -1) {
					visit[xx][yy] = visit[x][y] + 1;
					q.push({ xx, yy });
				}
			}
		}
	}
	cout << visit[n - 1][m - 1] << '\n';
}

// n*m 보드에서 각 칸에 적힌 숫자까지 우측/하단으로 이동할 수 있을 때, 좌측 상단에서 우측 하단까지 이동하는데 걸리는 최소 시간은?

// 평범한 bfs - 이동 방향이 상하좌우가 아니라 우하 n칸까지일 뿐
// 따라서 탐색 과정을 우측 1~n칸, 하단 1~n칸으로 하여 탐색한 후 도착 지점에 도달한 경우 탐색 중단하고 출력하기