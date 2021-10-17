// BOJ 거리
// https://www.acmicpc.net/problem/12026

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> dp(n, 987654321);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] == 987654321) {
			continue;
		}
		for (int j = i + 1; j < n; j++) {
			if ((s[i] == 'B' && s[j] == 'O') || (s[i] == 'O' && s[j] == 'J') || (s[i] == 'J' && s[j] == 'B')) {
				dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
			}
		}
	}
	if (dp[n - 1] == 987654321) {
		dp[n - 1] = -1;
	}
	cout << dp[n - 1] << '\n';
}

// B부터 시작하는 문자열의 처음부터 끝까지 B O J 순서대로 밟으며 지나가는 상황에서 k칸을 뛰어 넘어가는 에너지 비용이 k * k일 떄, 마지막 칸으로 갈 수 있는가? 갈 수 있다면 최소 비용은 얼마인가?

// 길이가 1000까지이므로 n^2 기반으로 풀 수 있는 dp 문제
// dp 배열의 첫 칸은 0, 나머지는 INF로 설정한 뒤 첫 칸부터 그 뒤의 칸들과 매칭하면서 dp 갱신
// 만약 시작하는 칸의 dp가 INF가 아니고 뒤에 선택한 칸이 갈 수 있는 칸이라면 도착칸 dp와 시작칸 dp + 간격^2 중 작은 값으로 갱신
// 이렇게 모든 칸의 dp를 갱신한 후 마지막칸 dp가 INF면 -1, 그렇지 않다면 해당 값 출력