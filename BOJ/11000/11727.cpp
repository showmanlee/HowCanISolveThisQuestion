// 2×n 타일링 2
// https://www.acmicpc.net/problem/11727

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	cout << dp[n] << '\n';
}

// 2×n 타일링 1은 피보나치 문제였음 - 근데 여기서는 =을 ㅁ으로 대체할 수 있음
// 1 = 1	|
// 2 = 3	|| = ㅁ
// 3 = 5	||| |= =| |ㅁ ㅁ|
// 4 = 11	|||| ||= |=| =|| ||ㅁ |ㅁ| ㅁ|| ㅁㅁ ㅁ= =ㅁ ==
// 5 = 21	||||| |||= ||=| |=|| =||| |||ㅁ ||ㅁ| |ㅁ|| ㅁ||| |== |ㅁ= |=ㅁ |ㅁㅁ =|= =|ㅁ ㅁ|= ㅁ|ㅁ ==| =ㅁ| ㅁ=| ㅁㅁ|
// 점화식 - dp[0] = 1, dp[1] = 1, dp[i] = dp[i - 1] + dp[i - 2] * 2