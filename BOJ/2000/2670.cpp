// 연속부분최대곱
// https://www.acmicpc.net/problem/2670

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<double> dp(n);
	cin >> dp[0];
	double res = dp[0];
	for (int i = 1; i < n; i++) {
		cin >> dp[i];
		dp[i] = max(dp[i], dp[i - 1] * dp[i]);
		res = max(res, dp[i]);
	}
	printf("%.3lf\n", res);
}

// 실수로 구성된 수열에서 연속된 수들의 곱이 최대가 되는 경우의 값은?

// 최대 연속합 구하는 원리와 비슷하게 적용 - 실수의 범위가 음수가 아니기 때문에 가능
// dp[i]를 입력한 후, dp[i - 1] * dp[i]와 비교하여 더 큰 값을 저장 - 합과 마찬가지로, 이번 회차에서 값이 줄어든다면 이후에도 최댓값이 되지 않음이 보장됨
// 이후 dp를 순회하며 가장 높은 값을 뽑아내면 그게 답 - 물론 dp[i]가 갱신되는 순간에 최댓값을 판정해도 됨
// 정확히 소수점 뒤 3자리를 출력해야 하므로 printf 사용하기