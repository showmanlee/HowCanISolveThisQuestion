// 다이나믹이 뭐예요?
// https://www.acmicpc.net/problem/14494

#include <iostream>
using namespace std;
long long dp[1001][1001] = { {0,}, };

int main(void) {
	int n, m;
	cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i][j - 1]) % 1000000007;
	cout << dp[n][m] << '\n';
}

// 이미 문제에서 점화식을 제시함 - dp[i][j] = dp[i-1][j] + dp[i][j-1]
// 문제는 이 점화식에서 대각선 방향을 추가해야 한다는 것
// 1 1 1
// 1 3 5
// 1 5 13
// 나머지한 값을 3번 더하면 21억이 넘을 수도 있기에 long long으로 처리