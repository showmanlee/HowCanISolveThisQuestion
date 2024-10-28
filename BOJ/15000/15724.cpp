// 주지수
// https://www.acmicpc.net/problem/15724

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + board[i][j];
        }
    }
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--;
        b--;
        int res = dp[x][y] - dp[a][y] - dp[x][b] + dp[a][b];
        cout << res << '\n';
    }
}

// 정수가 적힌 n*m 보드에서 주어진 범위 합 구하기

// 2차원 부분합 dp