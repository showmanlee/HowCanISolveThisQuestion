// 가장 큰 정사각형
// https://www.acmicpc.net/problem/1915

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '1')
				dp[i][j] = 1;
		}
	}
	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (dp[i][j] != 0 && dp[i][j - 1] != 0 && dp[i - 1][j] != 0 && dp[i - 1][j - 1] != 0) {
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
				res = max(res, dp[i][j]);
			}
		}
	}
	for (int i = 0; i < m; i++)
		if (dp[0][i] == 1 && res == 0)
			res = 1;
	for (int i = 0; i < n; i++)
		if (dp[i][0] == 1 && res == 0)
			res = 1;
	cout << (res * res) << '\n';
}

// n * m 배열에서 1이 이루는 가장 큰 정사각형의 크기는?
// 2차원 dp의 시작 - 한 칸에는 내 좌측 상단부터 시작되어 여기까지 완성된 정사각형의 크기를 표시
// 내 좌상단들이 빈 공간이 아닐 때, 좌상단 중 최소 + 1로 dp 갱신하기
// 한 변이 1인 경우, 그리고 2 이상이더라도 가장자리에만 1이 있는 경우에 주의 - 만약 탐색하지 못한 0번 인덱스에 1이 있는데 누적된 크기가 0이라면 크기를 1로 세팅