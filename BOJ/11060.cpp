// 점프 점프
// https://www.acmicpc.net/problem/11060

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n), dp(n, 987654321);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= board[i]; j++) {
			if (i + j >= n)
				break;
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n - 1] == 987654321)
		dp[n - 1] = -1;
	cout << dp[n - 1] << '\n';
}

// 1차원 배열에서 좌측으로 우측으로 이동하기 위해 칸에 적힌 수만큼 오른쪽으로 이동할 수 있을 때, 마지막 칸으로 이동하는데 드는 최소 이동 횟수는?

// dp로 푸는 최단거리 탐색 문제
// 우선 보드를 모두 받고, 1차원 dp 배열을 0 빼고 모두 최댓값으로 맞춘다
// 이후 왼쪽부터 보드를 순회하며, 칸의 적힌 숫자 범위만큼 오른쪽 칸들의 dp값을 현재값과 dp[i] + 1중 작은 값으로 갱신한다
// 만약 dp 마지막칸이 갱신되지 않았으면 접근이 불가능하다는 뜻, 그렇지 않다면 마지막칸이 답