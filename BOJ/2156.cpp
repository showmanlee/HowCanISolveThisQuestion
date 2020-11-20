// 포도주 시식
// https://www.acmicpc.net/problem/2156

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, res = 0;
	cin >> n;
	vector<int> wine(n + 3);
	vector<int> dp(n + 3);
	for (int i = 3; i < n + 3; i++)
		cin >> wine[i];
	for (int i = 3; i < n + 3; i++) {
		dp[i] = max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]);
		dp[i] = max(dp[i], dp[i - 1]);
		if (res < dp[i])
			res = dp[i];
	}
	cout << res << '\n';
}

// 이건 DP를 어떻게 짜주는 게 좋을까
// 3잔만 연속해서 안 마시는 거니까 점화식은 2개
// 1. dp[i - 2] + wine[i]					// 지금 새로 마시기 - i-2번째에 합산
// 2. dp[i - 3] + wine[i - 1] + wine[i]     // 지금 두 번 연달아 마시기 - i-3번째에 합산
// 그러나 두 번 연속 안 먹을 수도 있기 때문에 dp[i - 1]와 dp[i]를 한번 더 비교해줘야 함!
// 이러한 점화식 구조 때문에 앞에 3칸을 비워두고 시작