// 자원 캐기
// https://www.acmicpc.net/problem/14430

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}
	dp[1][1] = v[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = v[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m] << '\n';
}

// 2차원 배열에서 좌측 상단에서 우측 하단으로 우/하 방향으로 내려가면서 자원을 채취할 때, 우측 하단까지 아동하면서 캘 수 있는 자원의 최대 개수는?

// 2차원 dp - 내 상단/좌측의 칸에서 얻은 자원 최댓값과 현재 위치의 자원 값의 합