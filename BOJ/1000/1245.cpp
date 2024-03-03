// 농장 관리
// https://www.acmicpc.net/problem/1245

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

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

    vector<vector<bool>> visit(n, vector<bool>(m));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j]) {
                queue<pr> q;
                q.push({i, j});
                visit[i][j] = true;
                bool higher = false;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int t = 0; t < 8; t++) {
                        int xx = x + dx[t];
                        int yy = y + dy[t];
                        if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
                            continue;
                        }
                        if (board[xx][yy] > board[i][j]) {
                            higher = true;
                        }
                        if (board[xx][yy] == board[i][j] && !visit[xx][yy]) {
                            visit[xx][yy] = true;
                            q.push({xx, yy});
                        }
                    }
                }
                if (!higher) {
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}

// 각 칸마다 높이가 다른 n*m 보드에서 봉우리(8방향으로 인접한 같은 높이 영역에서 인접한 더 높은 지형이 없는 경우) 개수 구하기

// bfs로 영역 잡고, 탐색하면서 더 높은 지형 있는지 확인하고, 없으면 봉우리로 판정