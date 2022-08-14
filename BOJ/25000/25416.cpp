// 빠른 숫자 탐색
// https://www.acmicpc.net/problem/25416

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<vector<int>> board(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    int sx, sy;
    cin >> sx >> sy;
    vector<vector<int>> visit(5, vector<int>(5, -1));
    visit[sx][sy] = 0;
    queue<prr> q;
    q.push({{sx, sy}, 0});
    int res = -1;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int len = q.front().second;
        q.pop();
        if (board[x][y] == 1) {
            res = len;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= 5 || yy >= 5 || visit[xx][yy] != -1) {
                continue;
            }
            if (board[xx][yy] != -1) {
                visit[xx][yy] = len + 1;
                q.push({{xx, yy}, len + 1});
            }
        }
    }
    cout << res << '\n';
}

// -1, 0, 1이 적힌 5*5 보드에서 특정 위치에서 -1을 밟지 않고 1로 가는 최단 거리 출력하기

// bfs 기본 문제 - 보드도 고정 사이즈로 제공됨
// 따라서 기본 bfs 처리법을 이용해 풀 수 있도록...