// 1로 만들기
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];

int main(void) {
	int n;
	cin >> n;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[n] << endl;
}

// 알고 보면 dp 문제
// 1000001칸의 배열에 세 가지 연산 중 가장 작은 연산 카운트 수를 저장해 이어나가기
// dp[1] == 0으로 두고, 그 이후 dp[i - 1] + 1(1 빼기), dp[i / 2] + 1(2로 나누기), dp[i / 3	] + 1(3로 나누기) 중 가장 작은 값을 dp[i]에 매칭시킨다