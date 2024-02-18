// W키가 빠진 성원이
// https://www.acmicpc.net/problem/28471

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[7] = {-1, 0, 1, 1, 0, -1, -1};
int dy[7] = {-1, -1, -1, 1, 1, 1, 0};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    vector<vector<bool>> visit(n, vector<bool>(n));
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'F') {
                sx = i;
                sy = j;
            }
        }
    }
    queue<pr> q;
    q.push({sx, sy});
    visit[sx][sy] = true;
    int res = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 7; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= n || board[xx][yy] == '#') {
                continue;
            }
            if (!visit[xx][yy]) {
                visit[xx][yy] = true;
                res++;
                q.push({xx, yy});
            }
        }
    }
    cout << res << '\n';
}

// 8방향 중 전진을 제외한 7방향만 입력할 수 있을 때, 벽이 있는 n*n 보드에서 도착점까지 이동할 수 있는 칸의 수는?

// 반대로 후진을 제외한 7방향만 입력할 수 있을 때, 도착점에서 도달할 수 있는 칸의 개수를 찾아봅시다 - bfs로!