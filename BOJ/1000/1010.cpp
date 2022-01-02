// 다리 놓기
// https://www.acmicpc.net/problem/1010

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> dp(31, vector<int>(31));
    for (int i = 1; i <= 30; i++)
        dp[1][i] = i;
    for (int i = 2; i <= 30; i++)
        for (int j = i; j <= 30; j++)
            for (int k = j - 1; k >= 1; k--)
                dp[i][j] += dp[i - 1][k];
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
}

// 강 왼편에 n개의 지점이 있고, 오른편에 m개의 지점이 있을 때, 

// mCn을 구하는 방법도 있지만, 이를 위해 팩토리얼을 구하는 과정에서 long long 범위를 벗어나게 됨
// 사실 이 문제는 DP로 풀 수 있음 - dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j - 2] + ... + dp[i - 1][i - 1]
// dp[1][i] = i - 왼쪽에 한 개의 지점이 있으면 오른쪽으로 i개의 다리를 놓을 수 있다
// 여기서 왼쪽의 수가 하나 늘어나면, 추가된 점에 다리를 하나 놓은 후 경우의 수는 다리가 놓인 위치에 따라 dp[i - 1][j - 1] ~ dp[i - 1][1]이 됨
// 그리고 n > m일 때 dp[n][m] = 0이므로, dp[n][m]을 구히기 위해서는 dp[n - 1][m - 1] ~ dp[n - 1][1]까지의 합을 구하면 되는 것
// 이렇게 얻은 점화식을 이용해 dp를 채우기 위해 n^3 for 활용하기
// n <= m임이 보장되므로 반대편까지 dp를 채울 필요는 없음