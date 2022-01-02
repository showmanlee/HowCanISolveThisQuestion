// 쉬운 계단 수
// https://www.acmicpc.net/problem/10844

#include <iostream>
using namespace std;

int main(void) {
	int n;
	long long dp[101][11] = { {0,}, };
	cin >> n;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] += dp[i-1][1];
		for (int j = 1; j <= 9; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
	}
	long long res = 0;
	for (int i = 0; i <= 9; i++)
		res += dp[n][i];
	res %= 1000000000;
	cout << res << '\n';
}

// 계단수 = 인접한 자릿수 숫자의 차이가 1일 경우 - DP로 풀 수 있음
// 끝부분이 0, 9가 아니라면 하나의 계단수는 2개의 계단수를 만들어낼 수 있다.
// 1에서 0이 튀어나오고, 8에서 9가 나올 수 있다
// 따라서 0/9 케이스가 아닌 것과 그런 것들을 분할해 계산하면 된다...
// 아예 끝자리 케이스별로 dp를 돌려도 됨