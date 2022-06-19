// 로봇 청소기
// https://www.acmicpc.net/problem/4991

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n, m;
		cin >> m >> n;
		if (n == 0 && m == 0) {
			break;
		}
		vector<vector<char>> board(n, vector<char>(m));
		int cnt = 0;
		int sx, sy;
		map<pr, int> index;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'o') {
					sx = i;
					sy = j;
					board[i][j] = '.';
				} else if (board[i][j] == '*') {
					index[{i, j}] = cnt++;
				}
			}
		}
		int res = 987654321;
		vector<vector<vector<int>>> visit(n, vector<vector<int>>(m, vector<int>(1 << cnt, 987654321)));
		queue<prr> q;
		q.push({{sx, sy}, 0});
		visit[sx][sy][0] = 0;
		while(!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int t = q.front().second;
			q.pop();
			if (t == (1 << cnt) - 1) {
				res = min(visit[x][y][t], res);
				continue;
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy][t] != 987654321) {
					continue;
				}
				if (board[xx][yy] != 'x') {
					visit[xx][yy][t] = visit[x][y][t] + 1;
					int tt = t;
					if (board[xx][yy] == '*') {
						tt |= 1 << index[{xx, yy}];
						visit[xx][yy][tt] = visit[xx][yy][t];
					}
					q.push({{xx, yy}, tt});
				}
			}
		}
		if (res == 987654321) {
			res = -1;
		}
		cout << res << '\n';
	}
}

// 2차원 공간에 로봇청소기와 더러운 칸(최대 10칸)이 주어질 때, 로봇청소기가 모든 더러운 칸을 치우는데 걸리는 시간은(불가능하면 -1)?

// 최단 거리는 bfs - 그런데 더러운 칸을 지우는 경우의 수까지 생각해야 함
// 따라서 visit 배열을 2^더러운 칸 개수만큼 확장하여 본다 - i번째 더러운 칸을 지우면 비트마스킹으로 마킹하도록
// 이를 위해 map으로 각 더러운 칸 좌표마다 인덱스를 부여한다
// 만약 모든 더러운 칸을 지웠다면 여기까지 간 거리를 보고 갱신할 수 있도록 처리