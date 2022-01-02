// 가장 긴 증가하는 부분 수열
// https://www.acmicpc.net/problem/11053

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
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (board[i] > board[j])
				dp[i] = max(dp[i], dp[j] + 1);
	int res = *max_element(dp.begin(), dp.end());
	cout << res << '\n';
}

// 주어진 수열에서 일부 수를 뽑아서 만들 수 있는 가장 긴 증가하는 부분 수열 구하기

// '가장 긴 증가하는 부분 수열' - LIS 문제의 시작
// 기본적으로 DP 기반입니다 - n^2 기반과 nlogn 기반이 있어요
// 일단 문제 이해를 위해 n^2 기반부터 풀어봅시다 - n = 1000
// dp에는 현재 인덱스의 수를 포함하여 만들 수 있는 LIS의 최대 길이를 저장 - dp[0] = board[0] = 0으로 초기화 후 1~n에서 보드 받기
// 이후 1~n까지 순회하며 자신 이전에 자신보다 작은 수를 가지고 있는 모든 인덱스에 대하여 dp[j] + 1의 최댓값을 dp[i]에 저장
// 이렇게 얻은 dp들 중 최댓값이 정답