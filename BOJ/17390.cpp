// 이건 꼭 풀어야 해!
// https://www.acmicpc.net/problem/17390

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> board(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	sort(board.begin() + 1, board.end());
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++)
		dp[i] = dp[i - 1] + board[i];
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << (dp[b] - dp[a - 1]) << '\n';
	}
}

// 정렬한 수열에 대해 특정 범위의 합 구하기

// 이렇게 긴 수열 안에서 이러한 쿼리를 연속으로 요구할 때는 누적합 dp를 써야 함 - 그런데 이제는 수열을 정렬까지 해야 함0
// dp[i] = i까지의 합 -> dp[j] - dp[i] = i + 1 ~ j까지의 합
// 이 원리를 이용해 수열을 정렬한 뒤 dp를 만들어 범위를 받아 dp[b] - dp[a - 1]을 출력하기
// 인덱스는 1부터 - dp[0] = 0