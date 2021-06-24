// 평범한 배낭
// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<pr> object(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> object[i].first >> object[i].second;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j < object[i].first)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - object[i].first] + object[i].second);
		}
	}
	cout << dp[n][k] << '\n';
}

// 각각의 무게와 가치가 다른 n개의 물건을 최대 용량이 k인 배낭 안에 넣을 때, 배낭에 넣을 수 있는 물건의 최대 가치는?

// 배낭(냅색) 문제의 시작 - 이런 문제는 dp로 푼다
// 2차원 형태의 dp로 관리 - i번째 물건을 넣는 차례에서 가방 용량이 j일 때 확보할 수 있는 최대 가치
// i는 1부터 세기 - 초기값은 dp[0][?] = 0
// 물건 -> 용량 순서로 2차원 for를 돌면서 현재 가방 용량이 선택한 물건을 넣기 부족하면 dp[i - 1][j] 넣기
// 선택한 물건을 넣을 수 있다면 dp[i - 1][j](현재 용량에서 해당 물건 넣기 전 상태)와 dp[i - 1][j - 현재 무게] + 현재 가치(현재 물건을 넣을 수 있을 만큼 공간이 확보된 가방에 실제로 물건을 넣었을 때)중 더 큰 것 넣기
// 이렇게 돌린 결과 dp[n][k]에 있는 값이 답이 됨

// 이렇게 무게와 가치가 주어졌을 때 제한된 무게로 최대의 가치를 찾는 문제가 배낭 문제
// 앞으로도 자주 나오니 기본 해결 방법을 기억해둡시다