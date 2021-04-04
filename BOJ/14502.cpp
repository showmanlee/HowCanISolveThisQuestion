// 연구소
// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[8][8];
int n, m;

int bfs(pr a, pr b, pr c, vector<pr> viruses) {
	vector<vector<bool>> visit(n, vector<bool>(m));
	board[a.first][a.second] = 1;
	board[b.first][b.second] = 1;
	board[c.first][c.second] = 1;
	queue<pr> q;
	for (pr p : viruses) {
		q.push(p);
		visit[p.first][p.second] = true;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (board[xx][yy] == 0 && !visit[xx][yy]) {
				visit[xx][yy] = true;
				q.push({ xx, yy });
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 0 && !visit[i][j])
				ret++;
	board[a.first][a.second] = 0;
	board[b.first][b.second] = 0;
	board[c.first][c.second] = 0;
	return ret;
}

int main(void) {
	cin >> n >> m;
	vector<pr> blanks, viruses;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				blanks.push_back({ i, j });
			else if (board[i][j] == 2)
				viruses.push_back({ i, j });
		}
	}
	int res = 0;
	for (int i = 0; i < blanks.size(); i++) 
		for (int j = i + 1; j < blanks.size(); j++) 
			for (int k = j + 1; k < blanks.size(); k++)
				res = max(res, bfs(blanks[i], blanks[j], blanks[k], viruses));
	cout << res << '\n';
}

// 연구소에 벽 3개를 세워 빈 공간 전체로 퍼지는 바이러스를 최대한 차단하려고 할 때, 안전 구역의 최대 개수는?
// 빈 칸들 중 벽 3개를 세울 곳을 정해 bfs를 돌려본다 - 브루트포스 + BFS
// 보드 크기가 최대 8*8 = 64칸이고 초기 바이러스의 개수는 2~10개이기 때문에 경우의 수가 최대 62 * 61 * 60 = 226920, 따라서 브루트포스로 접근 가능
// BFS용 함수를 따로 만들어서 해당 위치에 임시로 벽을 세워 BFS 돌리기