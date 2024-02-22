// チーズ (Cheese)
// https://www.acmicpc.net/problem/5558

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, t;
    cin >> n >> m >> t;
    int sx = 0, sy = 0;
    vector<vector<char>> board(n, vector<char>(m));
    vector<pr> sp(10);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') {
                sp[0] = {i, j};
            } else if (board[i][j] >= '1' && board[i][j] <= '9') {
                sp[board[i][j] - '0'] = {i, j};
            }
        }
    }
    int res = 0;
    for (int tt = 0; tt < t; tt++) {
        vector<vector<int>> visit(n, vector<int>(m, -1));
        queue<pr> q;
        q.push(sp[tt]);
        visit[sp[tt].first][sp[tt].second] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == sp[tt + 1].first && y == sp[tt + 1].second) {
                res += visit[x][y];
                break;
            }
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == 'X') {
                    continue;
                }
                if (visit[xx][yy] == -1) {
                    visit[xx][yy] = visit[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
    }
    cout << res << '\n';
}

// n*m 보드에서 1부터 끝까지 모두 먹을 수 있는 최단 거리 구하기

// S에서 1, 1에서 2... 이런 식으로 bfs 최단거리를 구한다