// 동전 2
// https://www.acmicpc.net/problem/2294

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> dp(k + 1, 987654321), coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	sort(coins.begin(), coins.end());
	dp[0] = 0;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (i - coins[j] >= 0)
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
	if (dp[k] == 987654321)
		dp[k] = -1;
	cout << dp[k] << '\n';
}

// n종류의 동전으로 k원을 만들 때, 필요한 동전의 최소 개수 구하기

// 1차원 dp로 접근 - 각 칸에는 해당 금액을 만들기 위한 동전 최소 개수를 기록, 초기값은 INF
// 주어진 동전들을 정렬하고, dp[0] = 0으로 설정하고 dp 갱신 시작
// 만약 현재 금액 - 선택한 동전이 0 이상이면, dp[i]와 dp[i - coins[j]] + 1 중 작은 값으로 dp[i]를 갱신하기
// 모든 과정을 마친 후 dp[k]를 출력하기 - INF에서 갱신되지 않았으면 -1 출력