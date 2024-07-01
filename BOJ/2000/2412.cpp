// 암벽 등반
// https://www.acmicpc.net/problem/2412

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;  

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    map<pr, bool> board;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        board[{x, y}] = true;
    }
    map<pr, int> visit;
    board[{0, 0}] = true;
    visit[{0, 0}] = 1;
    queue<pr> q;
    q.push({0, 0});
    bool done = false;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (y == t) {
            cout << (visit[{x, y}] - 1) << '\n';
            done = true;
            break;
        }
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int xx = x + i;
                int yy = y + j;
                if (xx < 0 || yy < 0 || xx > 1000000 || yy > t) {
                    continue;
                }
                if (board[{xx, yy}] && visit[{xx, yy}] == 0) {
                    visit[{xx, yy}] = visit[{x, y}] + 1;
                    q.push({xx, yy});
                }
            }
        }
    }
    if (!done) {
        cout << -1 << '\n';
    }
}

// (0, 0)에서 y 좌표가 t인 곳까지 가기 위해 주어진 n개의 칸 중 각 축 거리가 2 이하인 칸으로 이동할 수 있을 때, 최단 거리 구하기

// bfs - 그런데 칸 현황은 vector가 아닌 map으로 처리해야 함, 칸이 너무 많기 때문