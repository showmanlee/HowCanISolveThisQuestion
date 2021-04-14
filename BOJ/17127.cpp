// 벚꽃이 정보섬에 피어난 이유
// https://www.acmicpc.net/problem/17127

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int board[11];
int res;

void bf(int idx, int score, int count) {
	if (count == 4) {
		if (idx < n)
			return;
		res = max(res, score);
		return;
	}
	int sum = 1;
	for (int i = idx; i < n - 3 + count; i++) {
		sum *= board[i];
		bf(i + 1, score + sum, count + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	res = 0;
	bf(0, 0, 0);
	cout << res << '\n';
}

// 일렬로 놓여 있는 숫자가 적힌 벚꽃을 연속으로 네 덩어리로 나눈 후, 각 덩어리에 속한 숫자의 곱의 합을 구할 때, 최댓값은?
// 브포로 네 덩어리로 나누면 되지요 - 나무 수가 최대 10개
// 연속해서 가능한 범위까지 그룹을 만들어준 다음 다음 그룹으로 이동
// 네 덩어리가 모두 만들어져도 끝까지 사용된 게 아니면 계산하지 않기