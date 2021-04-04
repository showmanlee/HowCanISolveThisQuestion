// 계단 오르기
// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> stair(n), dp(n);
	for (int i = 0; i < n; i++)
		cin >> stair[i];

	dp[0] = stair[0];
	dp[1] = max(stair[0] + stair[1], stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	for (int i = 3; i < n; i++)
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	cout << dp[n - 1] << '\n';
}

// 각 칸마다 숫자가 적힌 계단에서 한 번에 1~2개의 계단을 오를 수 있고, 연속해서 3개의 계단은 오를 수 없을 때, 최대로 얻을 수 있는 합은?
// 점화식을 세워보자...
// dp[i] = dp[i - 2] + stair[i]						// 전전 계단에서 두 칸을 오를 때
// dp[i] = dp[i - 3] + stair[i - 1] + stair[i]		// 전전전 계단에서 두 칸을 오르고, 바로 연속으로 한 칸 더 오를 때
// 연속으로 세 칸을 밟을 수는 없으므로 점화식 역시 세 칸에 걸리지 않게 설정하는 것이 필요
// 이에 따라 dp[0~2]에는 값을 줘야 함 - 그 전에 가능한 모든 경우의 수의 최댓값으로 설정