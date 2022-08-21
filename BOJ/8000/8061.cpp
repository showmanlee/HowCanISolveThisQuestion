// Bitmap
// https://www.acmicpc.net/problem/8061

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
    queue<pr> q;
    vector<vector<int>> visit(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '1') {
                visit[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
                continue;
            }
            if (visit[xx][yy] == -1) {
                visit[xx][yy] = visit[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
}

// 0과 1이 적힌 n*m 보드에서 각 0에 대해 가장 가까운 1의 거리 구하기

// 0에서 1을 찾지 말고 1에서 0으로 나아간다 - bfs
// 보드를 받을 때 1을 모두 큐에 넣고, 이를 이용해 bfs를 돌리며 0들과의 거리를 구한다