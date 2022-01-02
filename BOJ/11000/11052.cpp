// 카드 구매하기
// https://www.acmicpc.net/problem/11052

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> cards(n + 1);
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> cards[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + cards[j]);
	}
	cout << dp[n] << '\n';
}

// 1~n장이 담긴 카드팩으로 정확히 n장의 카드를 구매할 때 낼 수 있는 금액의 최댓값은?

// dp 문제 - 각 칸에는 i장을 구매했을 때 낼 수 있는 최대 금액을 기록
// 1장 살 경우에는 무조건 1장 가격으로만 살 수 있음
// 2장 살 경우에는 1장 2개 또는 2장 하나의 경우가 있음
// 3장 살 경우에는 1장 3개, 1-2, 2-1, 3장 하나의 경우가 있음
// 위 경우를 다르게 보면, 1장을 산 뒤 (2장 사는 경우 중 비싸게 산 경우), 2장을 산 뒤 (1장 사는 경우 중 비싸게 산 경우), 3장을 산 뒤 (0장 사는 경우 중 비싸게 산 경우)로 일반화할 수 있음
// 따라서 이를 점화식화하면 dp[i] = max(dp[i], dp[i - j] + cards[j])
// 여기서 i는 사는 갯수, j는 1에서 i까지 가는 신규 카드팩 선택 인수