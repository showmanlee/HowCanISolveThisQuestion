// 벽 부수고 이동하기 2
// https://www.acmicpc.net/problem/14442

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> prrr;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(k + 1)));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int res = -1;
	queue<prrr> q;
	q.push({ {0, 0}, {1, 0} });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int broke = q.front().second.second;
		if (x == n - 1 && y == m - 1) {
			res = dist;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (broke < k && !visit[xx][yy][broke + 1] && board[xx][yy] == '1') {
				visit[xx][yy][broke + 1] = true;
				q.push({ {xx, yy}, {dist + 1, broke + 1} });
			}
			else if (!visit[xx][yy][broke] && board[xx][yy] == '0') {
				visit[xx][yy][broke] = true;
				q.push({ {xx, yy}, {dist + 1, broke} });
			}
		}
	}
	cout << res << '\n';
}

// 어떤 보드의 좌측 상단부터 우측 하단까지 이동하기 위해 k개의 벽을 깰 수 있을 때, 도달할 수 있는 최소 거리는?
// 1에서 했던 아이디어를 다시 써보자 - visit를 3차원(x, y, 벽 개수)로 만들어 벽을 부순 개수에 따라 visit 따로 보기
// 이번에는 부술 수 있는 벽의 개수가 여러 개기 때문에 조건문도 약간 바꿔야 함 - 여러 곳에서 동일한 visit에 접근할 수 있음