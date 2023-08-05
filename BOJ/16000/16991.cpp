// 외판원 순회 3
// https://www.acmicpc.net/problem/16991

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<double, double> pr;

int n;
pr board[17];
double dp[17][65536];

double dist(int a, int b) {
	double x = abs(board[a].first - board[b].first);
	double y = abs(board[a].second - board[b].second);
	return sqrt(x * x + y * y);
}

double tsp(int cur, int visit) {
	if (visit == (1 << n) - 1) {
		return dist(cur, 0);
	}
	if (dp[cur][visit] != 0) {
		return dp[cur][visit];
	}
	double ret = 98765432198765;
	for (int i = 0; i < n; i++) {
		if ((visit & (1 << i))) {
			continue;
		}
		ret = min(ret, tsp(i, visit | (1 << i)) + dist(cur, i));
	}
	dp[cur][visit] = ret;
	return ret;
}

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(16);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i].first >> board[i].second;
	}
	cout << tsp(0, 1) << '\n';
}

// n개의 도시 간 단방향 통행료가 주어질 때, 한 도시에서 중복 없이 모든 도시를 순회한 후 돌아오는 최소 비용 출력하기

// 외판원 순회 1 - 그런데 이제 도시가 좌표로 주어져서 거리를 두 점의 거리로 구해야 하는
// 똑같지 않을까요?