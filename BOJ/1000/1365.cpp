// 꼬인 전깃줄
// https://www.acmicpc.net/problem/1365

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
	int res = dp.size() - 1;
	cout << (n - res) << '\n';
}

// 한 포트에서 다른 포트로 선을 잇는 과정에서 선이 교차되면 안 될 때, 잘라내야 하는 전선의 최소 갯수 구하기

// 2352 반도체 설계와 요구사항이 같음 - 즉, 이것도 LIS
// 다만 여기서는 모두 연결된 상태에서 '잘라내야 하는 최소 갯수'를 구함 - 따라서 전체 길이에서 LIS의 길이를 뺀 게 답