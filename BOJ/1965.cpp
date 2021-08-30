// 상자넣기
// https://www.acmicpc.net/problem/1965

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

// 크기가 다른 상자들이 일렬로 놓여 있는 상황에서 순서대로 작은 상자를 큰 상자 속에 넣을 수 있을 때, 한 번에 넣을 수 있는 상자의 최대 개수는?

// 가장 긴 증가하는 부분 수열을 구하라는 문제 - n이 1000까지라 n^2 기반 알고리즘 적용 가능
// 다만 여기서는 더 좋은 알고리즘을 넣어서 풀어봤습니다
