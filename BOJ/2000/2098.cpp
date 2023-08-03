// 외판원 순회
// https://www.acmicpc.net/problem/2098

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

// 외판원 순회 문제(TMP)에 오신 것을 환영합니다 - 이 문제는 비트마스킹 기반 dp로 풀 수 있는데요
// 2차원 dp를 현재 있는 마을, 방문 현황으로 최소 거리를 기억하면서 풀어나가는 겁니다 + 재귀함수
// 어차피 다음에 방문할 순서가 중요하지, 이전 방문 순서는 중요하지 않기 때문에 방문 현황을 비트마스킹으로 기록, 이미 해당 방문 기록에 대한 최소 비용이 나온 상태라면 그걸 활용한다
// 다 돈 뒤 다시 출발지로 돌아올 수 있는 지 확인해야 함에 주의 - 어차피 한 바퀴 도는 문제기 때문에 어디서 출발하느냐는 중요하지 않음