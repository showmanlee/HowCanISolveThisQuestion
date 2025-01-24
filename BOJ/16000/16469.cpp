// 소년 점프
// https://www.acmicpc.net/problem/16469

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
    vector<vector<char>> board(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<vector<int>>> visit(3, vector<vector<int>>(n + 1, vector<int>(m + 1, -1)));
    for (int t = 0; t < 3; t++) {
        int sx, sy;
        cin >> sx >> sy;
        queue<pr> q;
        q.push({sx, sy});
        visit[t][sx][sy] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx <= 0 || yy <= 0 || xx > n || yy > m || board[xx][yy] == '1') {
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
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '1' || visit[0][i][j] == -1 || visit[1][i][j] == -1 || visit[2][i][j] == -1) {
                continue;
            }
            int p = max(visit[0][i][j], max(visit[1][i][j], visit[2][i][j]));
            if (p < res) {
                res = p;
                cnt = 1;
            } else if (p == res) {
                cnt++;
            }
        }
    }
    if (res == 987654321) {
        cout << -1 << '\n';
    } else {
        cout << res << '\n' << cnt << '\n';
    }
}

// 주어진 대소문자 문자열에서 특정 단어가 나오면 분류가 결정될 때, 분류 구하기