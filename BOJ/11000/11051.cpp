// 이항 계수 2
// https://www.acmicpc.net/problem/11051

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1));
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[n][k] << '\n';
}

// n과 k가 주어질 떄, 이항계수 % 10007 구하기

// n, k의 이항계수 -> n! / (k! * (n - k)!) = nCk
// 이제 n, k의 범위가 1000까지 주어지므로 생각 없이 팩토리얼을 넣어서 풀 수는 없음 - dp가 필요함
// nCk를 이용해 만들 수 있는 파스칼의 삼각형의 형태를 생각하면서 높이가 n+1인 삼각형 형태의 dp를 만든 후, 이를 구한다
// 파스칼의 삼각형은 맨 위 두 줄을 1 / 1 1로 시작하여 그 아랫줄은 양 사이드는 1로 채우고, 그 사이는 자신 위의 두 수의 합으로 채운 삼각형