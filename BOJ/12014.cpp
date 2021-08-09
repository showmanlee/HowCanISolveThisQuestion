// 주식
// https://www.acmicpc.net/problem/12014

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n, k;
		cin >> n >> k;
		vector<int> board(n), dp(1);
		for (int i = 0; i < n; i++)
			cin >> board[i];
		for (int i = 0; i < n; i++) {
			if (dp.back() < board[i])
				dp.push_back(board[i]);
			else
				*lower_bound(dp.begin(), dp.end(), board[i]) = board[i];
		}
		cout << "Case #" << t << '\n' << (dp.size() - 1 >= k) << '\n';
	}
}

// n일 중 지난 구매 시점보다 더 높은 주가에서만 주식을 구매하여 총 k일에 걸쳐 구매하려고 할 때, 그렇게 구매할 수 있는가?

// 다르게 말하면, LIS의 길이가 k 이상으로 나오는가를 묻는 문제
// n이 10000이므로 nlogn LIS로 LIS의 최대 길이(dp의 길이)를 구하고, 그 길이가 k 이상이면 1, 그렇지 않으면 0 출력

// 여기서 nlogn LIS 다시 복습합시다
// - nlogn LIS에서 사용되는 dp 안에는 해당 길이까지의 LIS를 만들때 드는 가장 작은 수를 기록한다 - 시작 인덱스는 dp[0] = MIN;
// - 이후 수열을 순회하면서, lower_bound(선택된 수와 같은 수가 나온 위치를 찾되, 그런 수가 없다면 그 다음으로 큰 수의 위치를 찾는 함수)로 선택된 수의 dp 위치를 찾아 해당 위치의 수를 선택된 수로 바꾼다
// - 만약 dp의 마지막 수가 선택된 수보다 작은 경우, LIS의 길이를 늘리며 새로운 인덱스에 선택된 수를 할당한다
// - 이렇게 나온 dp의 길이가 LIS의 길이가 되고, dp를 순회하면 LIS가 출력된다