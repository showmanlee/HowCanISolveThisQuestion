// 병사 배치하기
// https://www.acmicpc.net/problem/18353

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
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
    }
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (board[i] < board[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
	int res = n - (*max_element(dp.begin(), dp.end()));
	cout << res << '\n';
}

// 순서대로 선 병사들의 전투력 현황이 주어질 때, 전투력 순서를 내림차순으로 맞추면서 합을 최대로 맞추기 위해 빼야 하는 최소 인원수 구하기

// = 가장 긴 감소하는 부분 수열