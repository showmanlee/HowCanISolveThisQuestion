// Four Squares
// https://www.acmicpc.net/problem/17626

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> dp(n + 1, 987654321);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; i - j * j >= 0; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	cout << dp[n] << '\n';
}

// 어떤 수를 제곱수의 합으로 나타낼 때, 제곱수의 최소 개수 구하기

// 이미 어떤 자연수는 넷 이하의 제곱수의 합으로 나타낼 수 있음이 증명되었기 때문에 브포로도 접근할 수 있지만, dp로도 가능
// dp는 1차원 배열로, 각 인덱스를 구성하는데 필요한 제곱수의 수를 나타낸다 - 초기값은 MAX, dp[0] = 1
// dp를 갱신하는 과정은 2차원 for - i는 1부터 n까지, j는 i - j * j >= 0을 만족하는 제곱수의 계수
// 이렇게 인덱스를 돌면서 dp[i]를 dp[i]와 dp[i - j * j] + 1 중 작은 값으로 갱신
// 최종적으로 dp[n]을 구하여 정답으로 출력하기