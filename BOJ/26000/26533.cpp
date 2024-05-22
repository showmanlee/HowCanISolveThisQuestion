// Tractor Path
// https://www.acmicpc.net/problem/26533

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    queue<pr> q;
    q.push({0, 0});
    vector<vector<bool>> visit(n, vector<bool>(n));
    visit[0][0] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x + 1 < n && board[x + 1][y] == '.' && !visit[x + 1][y]) {
            q.push({x + 1, y});
            visit[x + 1][y] = true;
        }
        if (y + 1 < n && board[x][y + 1] == '.' && !visit[x][y + 1]) {
            q.push({x, y + 1});
            visit[x][y + 1] = true;
        }
    }
    cout << (visit[n - 1][n - 1] ? "Yes" : "No") << '\n';
}

// ax + b와 cx + d를 구성하는 x와 abcd가 주어질 때, 두 식의 값이 동일한지 판정하기

// 문제 설명을 직관적으로 하면 그렇다는 거지