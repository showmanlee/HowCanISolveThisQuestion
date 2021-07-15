// 가장 긴 증가하는 부분 수열 3
// https://www.acmicpc.net/problem/12738

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	vector<int> dp(1);
	dp[0] = -1000000001;
	for (int i = 0; i < n; i++) {
		if (dp.back() < board[i])
			dp.push_back(board[i]);
		else 
			*lower_bound(dp.begin(), dp.end(), board[i]) = board[i];
	}
	cout << (dp.size() - 1) << '\n';
}

// 주어진 수열에서 일부 수를 뽑아서 만들 수 있는 가장 긴 증가하는 부분 수열 구하기

// 가장 긴 증가하는 부분 수열 2에서 주어지는 수의 범위가 -10억까지 확장된 문제
// 따라서 dp[0]을 -10억-1로 바꾸고 들어가야 함 - 나머지는 종전과 동일