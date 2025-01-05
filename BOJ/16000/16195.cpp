// 1, 2, 3 더하기 9
// https://www.acmicpc.net/problem/16195

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    vector<vector<long long>> dp(1001, vector<long long>(1001));
    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            for (int k = 1; k <= 3; k++) {
                if (j - k <= 0) {
                    continue;
                }
                dp[j][i] += dp[j - k][i - 1];
                dp[j][i] %= 1000000009;
            }
        }
    }
    for (int t = 0; t < tt; t++) {
        int n, m;
        cin >> n >> m;
        long long res = 0;
        for (int i = 1; i <= m; i++) {
            res = (res + dp[n][i]) % 1000000009;
        }
        cout << res << '\n';
    }
}

// n을 m개까지의 1, 2, 3의 합으로 구하는 경우의 수 구하기