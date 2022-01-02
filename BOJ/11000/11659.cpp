// 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> num(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		dp[i] = dp[i - 1] + num[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << (dp[b] - dp[a - 1]) << '\n';
	}
}

// 수열이 주어질 때, i번째 수에서 j번째 수까지의 합 구하기
// dp 배열에 1~n번째 수의 합을 구한 후, dp[j] - dp[i - 1]로 구하면 매 구간마다 반복문을 돌릴 필요가 없음
// 수가 1번째부터 시작하기에, dp[0] = 0, dp[1] = num[1], dp[2] = dp[1] + num[2] = num[1] + num[2]... 방식으로 올라감
// 여기서 2~4번째 수의 합을 구하면 dp[4] - dp[1] = num[4] + num[3] + num[2] - num[1]이 되는 것