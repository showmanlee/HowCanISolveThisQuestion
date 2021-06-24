// 벼락치기
// https://www.acmicpc.net/problem/14728

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	vector<pr> lecture(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(t + 1));
	for (int i = 1; i <= n; i++)
		cin >> lecture[i].first >> lecture[i].second;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j < lecture[i].first)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - lecture[i].first] + lecture[i].second);
		}
	}
	cout << dp[n][t] << '\n';
}

// 공부해야 하는 시간과 시험 배점이 다른 n개의 과목을 t시간 안에 공부해야 할 때, 확보할 수 있는 최대 점수는?

// 기본적인 배낭 문제 - 해결 방법 복습
// 2차원 dp로 해결 - i는 현재 넣을 수 있는 물건 번호(1~n), j는 가방 용량
// i -> j 순으로 반복문을 돌면서, 현재 가방 용량(j)가 현재 물건(i) 무게보다 작다면 dp[i][j] = dp[i - 1][j] 
// 그렇지 않다면 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 무게] + 가치)
// dp[i - 1][j] = 현재 가방 무게에서 현재 물건을 넣기 전 확보할 수 있었던 가치의 최댓값
// dp[i - 1][j - 무게] + 가치 = 현재 물건을 넣을 수 있는 상태의 가방에 현재 물건을 넣었을 때 확보할 수 있는 가치의 최댓값
// 따라서 dp[n][t]는 현재 내 가방에서 마지막 물건까지 넣을 수 있었을 때 확보할 수 있는 가치의 최댓값