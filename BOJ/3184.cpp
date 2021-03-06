// 양
// https://www.acmicpc.net/problem/3184

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int bfs(vector<vector<char>> board, vector<vector<bool>>& visit, int i, int j, int n, int m) {
	int s = 0, w = 0;
	queue<pr> q;
	q.push({ i, j });
	if (board[i][j] == 'v')
		w++;
	else if (board[i][j] == 'o')
		s++;
	visit[i][j] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int t = 0; t < 4; t++) {
			int xx = x + dx[t];
			int yy = y + dy[t];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (!visit[xx][yy] && board[xx][yy] != '#') {
				visit[xx][yy] = true;
				if (board[xx][yy] == 'v')
					w++;
				else if (board[xx][yy] == 'o')
					s++;
				q.push({ xx, yy });
			}
		}
	}
	if (s > w)
		return -s;
	else
		return w;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int s = 0, w = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != '#' && !visit[i][j]) {
				int r = bfs(board, visit, i, j, n, m);
				if (r < 0)
					s += -r;
				else
					w += r;
			}
		}
	}
	cout << s << ' ' << w << '\n';
}

// 한 울타리 안에 양과 늑대의 수에 따라 더 많은 쪽만이 살아남을 때(동률일 때는 늑대), 살아남을 양과 늑대의 수는?
// 각 덩어리 당 bfs로 개수 체크하기