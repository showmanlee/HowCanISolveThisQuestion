// 책정리
// https://www.acmicpc.net/problem/1818

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
	cout << (n - dp.size() + 1) << '\n';
}

// 번호가 매겨진 책들이 꽂힌 순서가 주어질 떄, 이를 1부터 오름차순으로 정렬하기 위해 뽑아야 하는 책의 최수 수는?

// 처음부터 책들을 보며 가장 길게 증가하는 부분을 남기고 나머지를 모두 뽑아 정렬하면 이상적임
// 즉, 이 문제는 (n - LIS 길이)를 구하는 문제 - 지금 dp 체계에서는 (n - (dp.size() - 1))
// LIS는 nlogn 방식으로 풀기