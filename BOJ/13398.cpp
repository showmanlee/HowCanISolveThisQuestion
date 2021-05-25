// 연속합 2
// https://www.acmicpc.net/problem/13398

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][0] = dp[0][1] = num[0];
	int res = num[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + num[i], num[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + num[i]);
		res = max({ res, dp[i][0], dp[i][1] });
	}
	cout << res << '\n';
}

// 임의의 수열에서 연속된 정수들(그 중 하나를 빼도 됨)의 합으로 나타낼 수 있는 수 중 가장 큰 수는?

// 1912 연속합에서 하나를 뺴도 되는 경우가 추가된 것 - 이 문제 역시 dp 기반으로 풀 수 있음
// dp를 2차원으로 관리 - 안 뺀 경우, 뺀 경우
// 안 뺀 경우의 경우 원래 문제와 마찬가지로 dp[i - 1] + num[i]와 num[i] 중 큰 수로 결정
// 뺀 경우의 경우 dp[i - 1][0](처음으로 뺀 경우)와 dp[i - 1][1] + num[i](이미 뺀 경우에 누적) 중 큰 수로 결정
// 이렇게 dp를 갱신하면서 그 중 가장 큰 수를 결과값 삼아 출력하기