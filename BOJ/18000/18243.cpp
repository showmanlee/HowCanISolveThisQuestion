// Small World Network
// https://www.acmicpc.net/problem/18243

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> visit(n + 1, vector<int>(n + 1, -1));
    vector<vector<bool>> board(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = board[b][a] = true;
    }
    bool res = false;
    for (int t = 1; t <= n; t++) {
        queue<int> q;
        q.push(t);
        visit[t][t] = 0;
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i = 1; i <= n; i++) {
                if (board[p][i] && visit[t][i] == -1) {
                    visit[t][i] = visit[t][p] + 1;
                    q.push(i);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visit[i][j] == -1 || visit[i][j] > 6) {
                res = true;
                break;
            }
        }
        if (res) {
            break;
        }
    }
    cout << (res ? "Big" : "Small") << " World!\n";
}

// 친구 네트워크가 주어질 때, 모든 유저가 6단계 안에 모두 연결되는지 확인하기

// 각 유저별로 bfs를 돌리며 거리를 측정한다 - 그리고 여기서 7단계 이상이 나오면 안 되는 걸로
// 모든 유저가 연결되어 있다는 보장이 없음 - 아예 연결되지 않았을 때도 안 된다고 해야 함