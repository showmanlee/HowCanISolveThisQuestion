// 정상 회담 2
// https://www.acmicpc.net/problem/1670

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = dp[2] = 1;
    for (int i = 4; i <= n; i += 2) {
        for (int j = 0; j <= i - 2; j += 2) {
            dp[i] += dp[j] * dp[i - j - 2];
            dp[i] %= 987654321;
        }
    }
    cout << dp[n] << '\n';
}

// 원탁에 둘러앉은 n명의 사람들이 팔을 서로 교차하지 않고 모두 악수하는 경우의 수 구하기

// 먼저 두 사람이 악수를 하면 양옆에 공간이 생기는데, 그 공간에 남은 인원수의 dp를 구한다
// 이를 위해서 0/2명일 때 케이스를 1로 두고, 4명일 떄부터 양쪽에 남은 인원수 dp를 곱한다
// 남은 인원이 홀수일 경우 무조건 겹치게 되니 dp는 0이 됨