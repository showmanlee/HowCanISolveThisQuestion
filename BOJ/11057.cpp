// 오르막 수
// https://www.acmicpc.net/problem/11057

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(10));
	
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= 10007;
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= 9; i++)
		res += dp[n][i];
	res %= 10007;
	cout << res << '\n';
}

// 인접한 수가 오름차순을 이루는 n자리 '오르막 수'의 개수(% 10007)는?
// dp 문제 - 각 자릿수 별로 dp 칸을 만들어둔다
// 만약 현재 자리가 0이라면 그 앞에 모든 수가 와도 오르막 수가 되지만, 9인 경우에는 9가 와야만 오르막 수가 된다
// 각 자릿수에 등장하는 수마다 등장하는 경우의 수가 다르기 때문에 dp 역시 2차원으로 마련해줘야 함
// 따라서 dp[i][0] = sum(dp[i-1][0~9])일 것이고, dp[i][9] = dp[i - 1][9]일 것이다
// 우리가 원하는 결과는 sum(dp[n][0~9]) % 10007