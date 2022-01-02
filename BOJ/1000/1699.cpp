// 제곱수의 합
// https://www.acmicpc.net/problem/1699

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> dp(n + 1);
	for (int i = 0; i <= n; i++)
		dp[i] = i;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	cout << dp[n];
}

// 어떤 수를 제곱수의 합으로 나타낼 때, 최소로 필요한 항의 수는?

// 그리디 문제는 아님 - 무조건 높은 제곱수를 사용하는 것이 능사는 아님
// 대신 여기서는 dp를 활용해야 함 - 가장 작은 제곱수인 1을 n개 사용한 결과를 초기 dp 배열에 저장한 후, 이를 줄여나간다
// 어떻게? - 2부터 n까지 나아가면서 그 사이에 존재하는 4 이상의 제곱수를 뺀 dp + 1이 현재 dp보다 작은 경우 그걸로 갱신
// 2 또는 2^2부터 탐색하는 이유 - 이미 1과 1^1에 대한 결과를 dp 초기화 과정에서 탐색했음
// dp 갱신에 +1을 붙이는 이유 - 갱신에 활용할 dp에서 제곱수 하나를 더해서 +1이 되기 때문