// 연속합
// https://www.acmicpc.net/problem/1912

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n), dp(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	int res = board[0];
	dp[0] = board[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + board[i], board[i]);
		res = max(dp[i], res);
	}
	cout << res << '\n';
}

// 주어진 수열에서 연속된 수들로 얻을 수 있는 합 중 가장 높은 값은?
// 10만 개의 수열 - 당연히 dp로 접근해야 한다
// dp[i]는 dp[i - 1] + board[i]와 board[i] 중 더 큰 값을 저장
// 만약 지금까지의 합이 음수거나 해서 board[i]보다 작은 경우, 여기다가 수를 계속 더한다 해도 최대 연속합이 아니게 됨
// 따라서 지금까지의 연속합을 버리고 board[i]부터 시작하는 새로운 연속합 시작하기
// dp를 갱신하면서 결과값도 최댓값으로 갱신시킨 후, 순회 종료 시 출력하기