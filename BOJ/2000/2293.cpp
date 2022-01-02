// 동전 1
// https://www.acmicpc.net/problem/2293

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> coins(n), dp(k + 1);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= k; j++)
			if (j - coins[i] >= 0)
				dp[j] += dp[j - coins[i]];
	cout << dp[k] << '\n';
}

// n개의 동전으로 k원을 만드는 경우의 수 구하기

// dp 기반으로 접근 - dp[i] = i원을 만드는데 필요한 수
// 2차원 for를 통해서 dp를 채워야 한다 - 초기화를 위해 dp[0] = 1, 나머지는 0으로 설정
// 이후 각 동전에 대해 동전 가치 ~ k까지의 범위 내에서 dp[현재 돈]에 dp[현재 돈 - 동전]을 더해주기 - dp로 쌓은 만드는 방법 수 + 현재 동전 = 만드는 방법 수(기본적 방법이 바뀌지 않으니)
// 이렇게 dp를 만들어서 dp[k] 출력하기