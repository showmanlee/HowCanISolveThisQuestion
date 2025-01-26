// 도시와 비트코인
// https://www.acmicpc.net/problem/31575

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
    cin >> m >> n;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<bool>> visit(n, vector<bool>(m));
    queue<pr> q;
    q.push({0, 0});
    visit[0][0] = true;
    bool res = false;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            res = true;
            break;
        }
        int xx = x + 1;
        int yy = y + 1;
        if (xx < n && board[xx][y] == 1 && !visit[xx][y]) {
            visit[xx][y] = true;
            q.push({xx, y});
        }
        if (yy < m && board[x][yy] == 1 && !visit[x][yy]) {
            visit[x][yy] = true;
            q.push({x, yy});
        }
    }
    cout << (res ? "Yes" : "No") << '\n';
}

// n*m 보드에서 출발점에서 도착점까지 중간 지점 하나를 들러 가는 최소 거리 구하기