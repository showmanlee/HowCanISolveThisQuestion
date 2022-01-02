// 반도체 설계
// https://www.acmicpc.net/problem/2352

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

// 한 포트에서 다른 포트로 선을 잇는 과정에서 선이 교차되면 안 될 때, 가능한 최대 연결 개수 구하기

// 겹치지 않게 차곡차곡 연결해야 하는 것이 LIS와 같음
// 따라서 LIS 알고리즘을 그대로 대입하여 해결