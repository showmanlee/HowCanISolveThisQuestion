// 외판원 순회 2
// https://www.acmicpc.net/problem/10971

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int board[17][17];
int dp[17][65536];

int tsp(int cur, int visit) {
	if (visit == (1 << n) - 1) {
		if (board[cur][0] == 0) {
			return 987654321;
		}
		return board[cur][0];
	}
	if (dp[cur][visit] != 0) {
		return dp[cur][visit];
	}
	int ret = 987654321;
	for (int i = 0; i < n; i++) {
		if (board[cur][i] == 0 || (visit & (1 << i))) {
			continue;
		}
		ret = min(ret, tsp(i, visit | (1 << i)) + board[cur][i]);
	}
	dp[cur][visit] = ret;
	return ret;
}

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cout << tsp(0, 1) << '\n';
}

// n개의 도시 간 단방향 통행료가 주어질 때, 한 도시에서 중복 없이 모든 도시를 순회한 후 돌아오는 최소 비용 출력하기

// 외판원 순회 1보다 n의 범위가 작아져서 브루트포스/dfs로도 구할 수 있게 된 사양
// 1과 똑같이 만들어주면 됩니다