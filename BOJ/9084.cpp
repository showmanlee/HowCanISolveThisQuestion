// 동전
// https://www.acmicpc.net/problem/9084

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<int> coins(n);
		for (int i = 0; i < n; i++)
			cin >> coins[i];
		int k;
		cin >> k;
		vector<int> dp(k + 1);
		dp[0] = 1;
		for (int j = 0; j < n; j++)
			for (int i = 1; i <= k; i++)
				if (i - coins[j] >= 0)
					dp[i] += dp[i - coins[j]];
		cout << dp[k] << '\n';
	}
}

// n종류의 동전으로 k원을 만드는 방법의 수는?

// 2293 동전 1의 멀티 테케 버전 - 따라서 해결볍도 동전 1과 같음