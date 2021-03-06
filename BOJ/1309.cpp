// 동물원
// https://www.acmicpc.net/problem/1309

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	cout << dp[n] << '\n';
}

// n열 2행인 우리에 사자를 넣는 케이스 수는? - 같은 행에 연속으로 사자를 넣을 수 없음
// 1 = 3 - 0 1 2
// 2 = 7 - 00 01 02 10 20 12 21
// 3 = 17 - 000 001 002 010 020 100 200 101 102 201 202 120 210 012 021 121 212
// 4 = 41 - 0000 0001 0002 0010 0020 0100 0200 1000 2000
//          1001 1002 2001 2002 1010 1020 2010 2020 0101 0102 0201 0202
//          1200 2100 0120 0210 0012 0021
//          1201 2101 1202 2102 1012 1021 2012 2021
//          1210 2120 0121 0212
//          1212 2121
// 점화식은 -> dp[0] = 1, dp[1] = 3, dp[i] = dp[i - 1] * 2 + dp[i - 2]