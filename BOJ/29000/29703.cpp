// 펭귄의 하루
// https://www.acmicpc.net/problem/29703

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

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    vector<pr> pts(2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') {
                pts[0] = {i, j};
            } else if (board[i][j] == 'H') {
                pts[1] = {i, j};
            }
        }
    }

    vector<vector<vector<int>>> visit(2, vector<vector<int>>(n, vector<int>(m, -1)));
    for (int t = 0; t < 2; t++) {
        queue<pr> q;
        q.push(pts[t]);
        visit[t][pts[t].first][pts[t].second] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == 'D') {
                    continue;
                }
                if (visit[t][xx][yy] == -1) {
                    visit[t][xx][yy] = visit[t][x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
    }
    
    int res = 987654321;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'F') {
                if (visit[0][i][j] != -1 && visit[1][i][j] != -1) {
                    res = min(res, visit[0][i][j] + visit[1][i][j]);
                }
            }
        }
    }
    if (res == 987654321) {
        res = -1;
    }
    cout << res << '\n';
}

// n*m 보드에서 출발점에서 도착점까지 중간 지점 하나를 들러 가는 최소 거리 구하기