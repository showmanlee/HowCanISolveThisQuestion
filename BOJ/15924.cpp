// 욱제는 사과팬이야!!
// https://www.acmicpc.net/problem/15924

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    dp[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1)
                continue;
            if (board[i][j] == 'E')
                dp[i][j] = dp[i][j + 1] % 1000000009;
            else if (board[i][j] == 'S')
                dp[i][j] = dp[i + 1][j] % 1000000009;
            else if (board[i][j] == 'B')
                dp[i][j] = (dp[i][j + 1] + dp[i + 1][j]) % 1000000009;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = (res + dp[i][j]) % 1000000009;
    cout << res << '\n';
}

// E/S/B가 적혀있는 n*m 보드에서 E는 우측, S는 하단으로 한 칸 이동하고, B는 우측 또는 하단으로 이동하는 칸일 때, 우측 하단까지 이동할 수 있는 경로의 수(% 1000000009)는?

// 2차원 경로의 개수를 찾는 DP 문제 - 우측 하단을 1로 잡고 올라가면서 경우의 수 추가하기
// E라면 오른쪽 칸에 쌓인 dp, S라면 아랫쪽 칸에 쌓인 dp를 더하고, B라면 두 방향에 쌓인 dp를 더한다 - int로 계산해도 나머지값끼리 오버플로가 일어나지 않음
// 그런데 시작점이 정확히 명시되어있지 않음 - 따라서 모든 칸에 적힌 경우의 수를 모두 합한 값이 정답이 됨