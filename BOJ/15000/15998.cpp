// 1, 2, 3 더하기 3
// https://www.acmicpc.net/problem/15988

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<long long> dp(1000001);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		cout << dp[p] << '\n';
	}
}

// 주어진 정수를 1, 2, 3을 더해서 만들 수 있는 경우의 수 구하기

// dp로 풀면 되는데 - 점화식을 만들어봅시다
// 1은 1, 2는 11 2, 3은 3 12 21 111로 만들 수 있음
// 그리고 4는 11111, 112, 121, 211, 22, 13, 31 이런 식으로 만들 수 있는데, 잘 보면 1 케이스에서 3을 더했을 때, 2 케이스에서 2를 더했을 때, 3 케이스에서 1을 더했을 때로 볼 수 있음
// 따라서 그 이후의 식들은 n-3에서 3을 더했을 때, n-2에서 2를 더했을 때, n-1에서 1을 더했을 때로 처리 가능
// 이렇게 처리해줍시다...