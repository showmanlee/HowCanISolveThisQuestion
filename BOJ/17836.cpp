// 공주님을 구해라!
// https://www.acmicpc.net/problem/17836

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> prrr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> board(n, vector<int>(m));
    vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(2)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    queue<prrr> q;
    q.push({ {0, 0}, {0, 0} });
    visit[0][0][0] = true;
    int res = 987654321;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second.first;
        int got = q.front().second.second;
        q.pop();
        if (time > t)
            continue;
        if (x == n - 1 && y == m - 1) {
            res = min(res, time);
            continue;
        }
        for (int i = 0; i < n; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy][got])
                continue;
            if (got == 1) {
                visit[xx][yy][got] = true;
                q.push({ {xx, yy}, {time + 1, got} });
            }
            else {
                if (board[xx][yy] == 2) {
                    visit[xx][yy][0] = visit[xx][yy][1] = true;
                    q.push({ {xx, yy}, {time + 1, 1} });
                }
                else if (board[xx][yy] == 0) {
                    visit[xx][yy][got] = true;
                    q.push({ {xx, yy}, {time + 1, got} });
                }
            }
        }
    }
    if (res == 987654321)
        cout << "Fail\n";
    else
        cout << res << '\n';
}

// n*m 보드에서 좌측 상단에서 우측 하단으로 k시간 안에 이동해야 하는 상황에서 보드 상의 전설의 검을 얻으면 벽을 무한정으로 뚫을 수 있을 때, k시간 내에 도달할 수 있는가? 있다면 최소 시간은?
// 2차원 bfs지만 검을 얻었을 때와 그렇지 않았을 때를 구분해야 함 - visit를 3차원으로 구성
// 검을 얻지 않았을 때는 벽의 위치를 보면서 bfs를 돌려야 하나, 검을 얻었다면 보드에서 벗어나지 않는 한 어디든 갈 수 있음
// bfs 탐색 중 시간을 기록하여, 시간이 k를 넘어서면 다음 탐색을 하지 않고 continue
// 만약 종점에 도달했다면 결과를 갱신하되, 다른 경우가 더 빠를 수 있으므로 큐 탈출은 하지 않음
// 그 결과 결과값이 갱신되지 않았다면(시간 내에 도달하지 못했다면) Fail, 그렇지 않으면 성공