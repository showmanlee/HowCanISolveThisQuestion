// 1학년
// https://www.acmicpc.net/problem/5557

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> board(n);
	vector<vector<long long>> dp(n, vector<long long>(21));
	for (int& i : board)
		cin >> i;
	
	dp[0][board[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0) {
				if (j + board[i] <= 20)
					dp[i][j + board[i]] += dp[i - 1][j];
				if (j - board[i] >= 0)
					dp[i][j - board[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 2][board[n - 1]] << '\n';
}

// 수열에서 0~n-2 숫자 사이에 +-를 넣은 결과값이 n-1이 되도록 만들고 싶다. 그러나 이 때 중간 결과값이 0~20 사이를 유지하도록 해야 할 때, 만들 수 있는 등식의 수는?
// 중간 결과까지 봐야 하고 숫자의 개수도 100개로 브포로는 풀 수 없음(2^99) - 답은 dp
// 2차원 dp를 만들자 - 사용하는 숫자 수 * 나오는 결과의 수가 각 칸에 저장됨
// 새롭게 연산한 결과가 범위 안에 있으면서 그 전 칸에 결과가 나오는 경우가 있다면 갱신