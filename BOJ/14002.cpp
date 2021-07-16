// 가장 긴 증가하는 부분 수열 4
// https://www.acmicpc.net/problem/14002

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n + 1), dp(n + 1), prev(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (board[i] > board[j]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					prev[i] = j;
				}				
			}
		} 
	}
	int resi = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[resi] << '\n';
	vector<int> res;
	while (resi != 0) {
		res.push_back(resi);
		resi = prev[resi];
	}
	reverse(res.begin(), res.end());
	for (int i : res)
		cout << board[i] << ' ';
	cout << '\n';
}

// 주어진 수열에서 일부 수를 뽑아서 만들 수 있는 가장 긴 증가하는 부분 수열을 구하고 출력하기

// n^2 기반 LIS에서 이전 노드를 기록하는 배열도 함께 만들기 - dp가 이전 dp + 1로 갱신되는 시점에 이전 인덱스를 저장
// 한번 탐색을 마친 dp는 이후에 갱신되지 않는다 - 그리고 다음 dp들은 이렇게 최종적으로 갱신된 이전 dp들을 통해 갱신된다
// 따라서 부분수열의 순서를 이런 식으로 누적하여 저장할 수 있는 것