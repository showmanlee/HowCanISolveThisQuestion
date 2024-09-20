// Maximum Subarray
// https://www.acmicpc.net/problem/10211

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        vector<int> v(n), dp(n);
        int res = -987654321;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (i == 0) {
                dp[i] = v[i];
            } else {
                dp[i] = max(v[i], v[i] + dp[i - 1]);
            }
            res = max(dp[i], res);
         }
         cout << res << '\n';
    }
}

// 주어진 수열의 가장 큰 부분 수열의 합 구하기