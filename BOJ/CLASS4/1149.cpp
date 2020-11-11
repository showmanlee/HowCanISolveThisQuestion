// RGB거리
// https://www.acmicpc.net/problem/1149

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(3));
	for (int i = 1; i <= n; i++)
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
	for (int i = 2; i <= n; i++) {
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
}

// 인접한 집에 같은 색을 칠할 수 없을 때, 모든 집을 칠할 수 있는 최소 비용 구하기
// 시작 지점이 R/G/B인 경우 3개를 만들어야 함
// 앞으로 나아가면서 바로 뒤의 집들 중 최소인 것을 찾아 더하면서 DP질을 하자