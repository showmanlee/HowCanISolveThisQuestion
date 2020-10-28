// BABBA
// https://www.acmicpc.net/problem/9625

#include <iostream>
using namespace std;

int main(void) {
	int n;
	int dp[46] = { 0, };
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n - 1] << ' ' << dp[n] << '\n';
}

// A -> B, B -> BA
// 근데 문자열을 구하는 문제가 아니라 AB 개수 구하는 문제
// A - 1 0
// B - 0 1
// BA - 1 1
// BAB - 1 2
// BABBA - 2 3
// BABBABAB - 3 5
// BABBABABBABBA - 5 8
// 그놈의 피보나치는 빠지는 일이 없네 - B는 일반 피보나치, A는 한칸 덜 가는 피보나치
// 45까지니까 int로 처리 가능