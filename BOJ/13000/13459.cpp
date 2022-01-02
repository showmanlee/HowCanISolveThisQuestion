// 구슬 탈출
// https://www.acmicpc.net/problem/13459

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
    int res = 0;
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
                res = 1;
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

// 미로 안에 구멍과 빨강/파랑 구슬이 있는 장난감을 상하좌우로 기울여 파란 구슬은 빠뜨리지 않고 빨간 구슬만 빠뜨리려고 할 때, 10번 이내로 기울여서 성공할 수 있는가?
// 모습은 다르지만 나름대로 최단 경로를 찾는 문제 - bfs
// 위치 입력을 받을 때 구슬 위치는 따로 저장해둔 뒤 보드에는 빈칸으로 남겨둔다 - 나중에 이동이 쉽도록
// visit는 빨간 구슬과 파란 구슬 모두의 위치를 잡아야 하기에 4차원으로 관리 - 2차원 2개로 관리하려다 실패했음

// bfs 큐 안에는 구슬들의 위치, 그리고 경과 시간을 기록한다 - tuple + pair
// 구슬을 이동할 때, 앞에 벽이 등장하거나 구멍에 빠질 때까지 계속 굴려준다
// 그러면서 각 구슬의 이동량도 함께 측정해준다 - 나중에 구슬이 겹칠 경우 처리를 위해
// 이후 각 구슬이 빠졌는지 판정 - 파란 구슬이 빠지면 continue, 빨간 구슬이 빠지면 성공 판정
// 구슬이 동시에 빠져도 아웃이기 때문에 파란 구슬 먼저 판정해주어야 한다
// 그리고 구슬의 위치가 겹친 경우 많이 이동한 쪽(= 뒤에 있던 쪽)의 구슬을 한 칸 뒤로 빼준다 - 이렇게 되려면 둘이 굴리는 방향의 같은 열/행에 있어야 함
// 이렇게 구슬 위치를 확정한 후, 방문하지 않은 경우의 경우 다음 큐에 넣어준다

// 스포: 구슬 탈출 2는 여기서 시간을 표시하는 버전, 3는 여기서 궤적을 표시하는 버전, 4는 2의 무제한 버전