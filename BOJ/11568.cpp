// 민균이의 계략
// https://www.acmicpc.net/problem/11568

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
	for (int i = 0; i < n; i++) {
		if (dp.back() < board[i])
			dp.push_back(board[i]);
		else
			*lower_bound(dp.begin(), dp.end(), board[i]) = board[i];
	}
	cout << (dp.size() - 1) << '\n';
}

// 제시된 수열에서 여러 개의 수를 선택해 남은 수가 증가하도록 남길 때, 남길 수 있는 가장 많은 개수는?

// LIS 구하라는 말
// n이 1000이므로 n^2로도 풀 수 있지만, nlogn을 알고 있으니 그쪽으로 푸는 게 더 빠름