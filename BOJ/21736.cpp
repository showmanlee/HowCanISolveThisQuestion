// 헌내기는 친구가 필요해
// https://www.acmicpc.net/problem/21736

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
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'I') {
				sx = i;
				sy = j;
			}
		}
	}
	queue<pr> q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	int res = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (board[x][y] == 'P')
			res++;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == 'X')
				continue;
			if (!visit[xx][yy]) {
				visit[xx][yy] = true;
				q.push({ xx, yy });
			}
		}
	}
	if (res == 0)
		cout << "TT\n";
	else
		cout << res << '\n';
}

// n*m 공간에서 헌내기(I)가 벽(X)에 막히지 않고 만날 수 있는 사람(P)의 수 구하기

// bfs 영역 탐색(dfs로도 됨)
// I에서 시작해 상하좌우로 영역을 확장하면서, P를 만나면 결과값에 누적하기
// 이후 결과가 0이라면 TT, 그렇지 않다면 수 출력하기