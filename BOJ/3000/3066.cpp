// 브리징 시그널
// https://www.acmicpc.net/problem/3066

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
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
}

// 한 포트에서 다른 포트로 선을 잇는 과정에서 선이 교차되면 안 될 때, 잘라내야 하는 전선의 최소 갯수 구하기
// 
// 1365 꼬인 전깃줄의 멀티 테케 버전 - 앞으로 교차된 선 떼기 문제는 nlogn LIS 문제인 것이라고 생각하면 됨