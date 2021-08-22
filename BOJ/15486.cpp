// 퇴사 2
// https://www.acmicpc.net/problem/15486

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> t(n + 2), p(n + 2), dp(n + 2);
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	for (int i = n; i >= 1; i--) {
		if (i + t[i] > n + 1)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
	}
	cout << dp[1] << '\n';
}

// n일 후 퇴사하려는 상담사가 n일까지의 상담 일정표에서 최대의 수익을 받고 떠나기 위해 선택한 경우의 수익은?
// 상담은 한 번 잡으면 여러 날이 걸리고, 그 기간 동안은 신규 상담을 잡을 수 없다 - 그리고 n일 이후에는 회사에 없기 때문에 일정 상 n일이 넘어가는 상담도 잡을 수 없다

// 퇴사 1(14501)에서는 n이 15까지라 브포로 풀 수 있었지만, 여기서는 n이 150만이므로 dp를 도입해야 함 - 사실 O(n) dp를 도입해도 오래걸림
// 여기서 dp는 뒤에서부터 채워나가야 한다 - 현재 일을 할 수 있는지 여부가 뒤 일정에 따라 결정되니까
// 만약 i + t[i]가 n + 1을 넘는다면, 그날은 일을 할 수 없다는 의미이므로 자신 뒤의 dp를 끌어온다
// 그렇지 않다면, 자신 뒤의 dp와 지금 일을 하고 쉰 이후(i + t[i])의 dp를 보고 더 큰 값을 자신의 dp로 삼는다
// 그렇게 구한 dp 배열 중 dp[1]을 출력하면 그게 답