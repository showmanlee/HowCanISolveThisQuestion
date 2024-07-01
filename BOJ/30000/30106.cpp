// 현이의 로봇 청소기
// https://www.acmicpc.net/problem/30106

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

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<bool>> visit(n, vector<bool>(m));
    queue<pr> q;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j]) {
                res++;
                q.push({i, j});
                visit[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int t = 0; t < 4; t++) {
                        int xx = x + dx[t];
                        int yy = y + dy[t];
                        if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy]) {
                            continue;
                        }
                        if (abs(board[x][y] - board[xx][yy]) <= k) {
                            visit[xx][yy] = true;
                            q.push({xx, yy});
                        }
                    }
                }
            }
        }
    }
    cout << res << '\n';
}

// 각 칸마다 높이가 다른 n*m 보드에서 높이차가 k칸 이하인 칸만 상하좌우로 건널 수 있을 때, 모든 칸을 방문하는데 필요한 경로의 수 구하기

// bfs로 세기