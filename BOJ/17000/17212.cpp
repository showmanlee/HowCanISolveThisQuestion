// 달나라 토끼를 위한 구매대금 지불 도우미
// https://www.acmicpc.net/problem/17212

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> dp(100001);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	dp[5] = 1;
	dp[6] = 2;
	dp[7] = 1;
	for (int i = 8; i <= n; i++) {
		int a = dp[i - 1] + 1;
		int b = dp[i - 2] + 1;
		int c = dp[i - 5] + 1;
		int d = dp[i - 7] + 1;
		dp[i] = min(a, min(b, min(c, d)));
	}
	cout << dp[n] << '\n';
}

// 1원, 2원, 5원, 7원 동전으로 n원을 지불할 때 사용할 수 있는 최소 동전 수는?

// 최소 횟수 구하기 dp 활용하기
// 1, 2, 5, 7원은 해당 동전을 내면 되니 1개
// 그 사이의 3(1 + 2), 4(2 + 2), 6(1 + 5)는 2개
// 그 이후부터는 dp[i - 1] + 1, dp[i - 2] + 1, dp[i - 5] + 1, dp[i - 7] + 1 중 가장 작은 값
// 여기서 n이 7 이하일 수도 있으니 배열 크기는 고정 선언하기