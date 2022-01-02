// 팰린드롬?
// https://www.acmicpc.net/problem/10942

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n + 1);
	vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
	for (int i = 1; i <= n; i++)
		cin >> board[i];

	for (int i = 1; i < n; i++) {
		dp[i][i] = true;
		if (board[i] == board[i + 1])
			dp[i][i + 1] = dp[i + 1][i] = true;
	}
	dp[n][n] = true;
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (board[j] == board[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = dp[j + i][j] = true;
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
}

// 수열의 특정 부분이 팰린드롬인지 확인하기
// 수열의 최대 길이는 2000 - 그러나 주어지는 쿼리의 수가 200만 - 일반적인 방법(a부터 b까지 순회)으로는 접근 불가
// 하지만 수열의 최대 길이가 2000이고 ^2해도 200만 - 팰린드롬 여부를 2차원 dp로 기록하는 것은 가능

// a에서 b까지가 팰린드롬인지 확인하는 dp[a][b]를 채우는 방법?
// - a == b라면 팰린드롬이 맞음, b-a == 1인 경우 board[a] == board[b]라면 역시 팰린드롬이 맞음 - 일단 여기까지는 O(n)으로 채우기
// - 이후 a와 b의 간격을 점점 벌려가면서 가능한 팰린드롬을 탐색 - board[a] == board[b]이고 dp[a + 1][b - 1]이면 이것도 팰린드롬
// - a와 b의 숫자가 같고, 그 안쪽이 팰린드롬이었으면 우리도 팰린드롬

// 이렇게 dp를 만들어둔 후 해당 결과를 이용해 쿼리 진행