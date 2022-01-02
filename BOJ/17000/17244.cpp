// 아맞다우산
// https://www.acmicpc.net/problem/17244

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> m >> n;
	vector<vector<char>> board(n, vector<char>(m));
	int cnt = 0, sx = 0, sy = 0, gx = 0, gy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (board[i][j] == 'E') {
				gx = i;
				gy = j;
			}
			else if (board[i][j] == 'X') {
				board[i][j] = '0' + cnt;
				cnt++;
			}
		}
	}
	int goal = 1 << cnt;
	vector<vector<vector<int>>> visit(n, vector<vector<int>>(m, vector<int>(goal, -1)));
	queue<prr> q;
	q.push({ {sx, sy}, 0 });
	visit[sx][sy][0] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if (x == gx && y == gy && t == goal - 1)
			break;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int tt = t;
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == '#')
				continue;
			if (board[xx][yy] >= '0' && board[xx][yy] <= '4')
				tt |= 1 << (board[xx][yy] - '0');
			if (visit[xx][yy][tt] == -1) {
				visit[xx][yy][tt] = visit[x][y][t] + 1;
				q.push({ {xx, yy}, tt });
			}
		}
	}
	cout << (visit[gx][gy][goal - 1]) << '\n';
}

// m*n 공간에 놓인 물건(X)을 모두 집고 출발점에서 도착점까지 이동하는데 걸리는 최소 시간은?

// 조건 충족 최단 거리 bfs
// 이런 류의 문제들이 그렇듯, 물건들은 개별로 카운트해야 함 - 각 물건에 인덱스를 두고, 비트마스킹으로 각 물건 습득 여부를 판별
// visit 배열은 3차원 - x, y, 물건 습득 여부
// 시작 지점부터 bfs를 돌리면서 물건을 습득하면 해당 물건 인덱스 비트를 1로 만들고 탐색 진행
// 그러한 방식으로 움직이다가 x와 y가 도착점에 도달하고, 물건 습득 비트가 모두 1이 되면 탐색 종료 - 모든 물건을 주울 수 있음이 보장됨
// 가로와 세로가 평소와 반대로 주어짐에 주의