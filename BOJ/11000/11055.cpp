// 가장 긴 증가 부분 수열
// https://www.acmicpc.net/problem/11055

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
		dp[i] = board[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (board[i] > board[j])
				dp[i] = max(dp[i], dp[j] + board[i]);
	int res = *max_element(dp.begin(), dp.end());
	cout << res << '\n';
}

// 어떤 수열의 증가하는 부분 수열 중 합이 가장 큰 결과는?

// 가장 긴 증가하는 부분 수열과 같은 원리 적용 - n^2를 돌면서 각 자리에 대한 최적의 dp 저장
// 그런데 여기는 저장되는 dp 값이 달라짐 - 해당 위치까지의 부분 수열의 합
// 하지만 가장 긴 증가하는 부분 수열이어야 하기 때문에 조건식 자체는 동일 - max 구분은 dp[i], dp[j] + board[i]로 변경할 뿐
// 그리고 이를 위해 dp[i]는 해당 인덱스의 board 값으로 둬야 함