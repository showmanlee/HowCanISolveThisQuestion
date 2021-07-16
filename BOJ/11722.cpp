// 가장 긴 감소하는 부분 수열
// https://www.acmicpc.net/problem/11722

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
	board[0] = 987654321;
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (board[i] < board[j])
				dp[i] = max(dp[i], dp[j] + 1);
	int res = *max_element(dp.begin(), dp.end());
	cout << res << '\n';
}

// 주어진 수열에서 일부 수를 뽑아서 만들 수 있는 가장 긴 감소하는 부분 수열을 구하기

// 증가하는 부분 수열의 감소하는 버전 - board[0]을 적당히 큰 수로 잡고, 비교식만 반대로 적어주면 됨