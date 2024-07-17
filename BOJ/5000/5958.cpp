// Space Exploration
// https://www.acmicpc.net/problem/5958

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    vector<vector<bool>> visit(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '*' && !visit[i][j]) {
                res++;
                queue<pr> q;
                q.push({i, j});
                visit[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int t = 0; t < 4; t++) {
                        int xx = x + dx[t];
                        int yy = y + dy[t];
                        if (xx < 0 || yy < 0 || xx >= n || yy >= n || board[xx][yy] != '*') {
                            continue;
                        }
                        if (!visit[xx][yy]) {
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

// n*n 보드에서 상하좌우로 이어지는 * 덩어리 개수 구하기