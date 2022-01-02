// 수강 과목
// https://www.acmicpc.net/problem/17845

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<pr> object(k + 1);
	for (int i = 1; i <= k; i++)
		cin >> object[i].first >> object[i].second;
	vector<vector<int>> dp(k + 1, vector<int>(n + 1));
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			if (j < object[i].second)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - object[i].second] + object[i].first);
		}
	}
	cout << dp[k][n] << '\n';
}

// 각 과목별 중요도와 공부 시간이 주어졌을 때, 제한된 시간 안에 공부하면서 최대로 얻을 수 있는 중요도는?

// 배낭 문제 -> 12865
// 기본적인 배낭 문제임으로 해결 방법도 평범한 배낭과 동일함 - 2차원 dp 기반으로
// 코드를 보면서 다시 복습합시다
