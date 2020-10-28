// 이친수
// https://www.acmicpc.net/problem/2193

#include <iostream>
using namespace std;

int main(void) {
	int n;
	long long dp[91] = { 0, };
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n] << '\n';
}

// 이친수 = 이진수인데 0으로 시작하지 않고 1이 연속으로 등장하지 않는 수
// 1 = 1
// 2 = 10
// 3 = 100 101
// 4 = 1000 1001 1010
// 5 = 10000 10001 10010 10100 10101
// 설마 너도 피보나치구나 -> 90까지니까 long long으로 처리