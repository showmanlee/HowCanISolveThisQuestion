// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef tuple<pr, pr, int> tpppi;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    vector<vector<vector<vector<bool>>>> visit(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m))));
    pr r, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                r = { i, j };
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                b = { i, j };
                board[i][j] = '.';
            }
        }
    }
    int res = -1;
    queue<tpppi> q;
    q.push({ r, b, 0 });
    visit[r.first][r.second][b.first][b.second] = true;
    while (!q.empty()) {
        int rx = get<0>(q.front()).first;
        int ry = get<0>(q.front()).second;
        int bx = get<1>(q.front()).first;
        int by = get<1>(q.front()).second;
        int time = get<2>(q.front());
        bool done = false;
        q.pop();
        if (time >= 10)
            continue;
        for (int i = 0; i < 4; i++) {
            int rxx = rx;
            int ryy = ry;
            int bxx = bx;
            int byy = by;
            int tr = 0;
            int tb = 0;
            while (board[rxx + dx[i]][ryy + dy[i]] != '#') {
                rxx += dx[i];
                ryy += dy[i];
                tr++;
                if (board[rxx][ryy] == 'O')
                    break;
            }
            while (board[bxx + dx[i]][byy + dy[i]] != '#') {
                bxx += dx[i];
                byy += dy[i];
                tb++;
                if (board[bxx][byy] == 'O')
                    break;
            }
            if (board[bxx][byy] == 'O')
                continue;
            if (board[rxx][ryy] == 'O') {
                res = time + 1;
                done = true;
                break;
            }
            if (rxx == bxx && ryy == byy) {
                if (tr > tb) {
                    rxx -= dx[i];
                    ryy -= dy[i];
                }
                else {
                    bxx -= dx[i];
                    byy -= dy[i];
                }
            }
            if (visit[rxx][ryy][bxx][byy])
                continue;
            visit[rxx][ryy][bxx][byy] = true;
            q.push({ {rxx, ryy}, {bxx, byy}, time + 1 });
        }
        if (done)
            break;
    }

    cout << res << '\n';
}

// 미로 안에 구멍과 빨강/파랑 구슬이 있는 장난감을 상하좌우로 기울여 파란 구슬은 빠뜨리지 않고 빨간 구슬만 빠뜨리려고 할 때, 10번 이내로 기울여서 성공할 수 있는가? 있다면 얼마나 걸리는가?
// 구슬 탈출 1에서 경과 시간을 표시해야 하는 버전
// res에서 1과 0을 기록했던 전작과 달리 이번에는 큐에서 같이 기록되고 있던 시간 정보를 저장한다
// 만약 탈출에 성공한 경우 현재 시간 + 1을 저장 후 탈출