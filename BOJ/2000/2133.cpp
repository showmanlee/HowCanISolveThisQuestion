// 타일 채우기
// https://www.acmicpc.net/problem/2133

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> dp(n + 2);
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2)
			dp[i] += dp[i - j] * 2;
	}
	cout << dp[n] << '\n';
}

// 3*n 보드에 1*2 타일을 가득 채우는 경우의 수는?

// dp 기반으로 푸는 문제 - 2*n 타일 채우기와 원리는 비슷한 문제
// 우선 n이 홀수면 결과값은 무조건 0 - 짝수 타일로 홀수를 채울 수는 없으니

// 2 - 3
// - -  | |  - - 
// | |  | |  - -
// | |  - -  - -
// 4 - 11            *******
// - - - -  - - - -  - - - -  - - - -                                 - - - -  | | - -  - - | |
// | | | |  | | - -  | - - |  - - | |  + - - - - 을 아래에 둔 경우 +  - - - -  | | | |  | | | |
// | | | |  | | - -  | - - |  - - | |                                 - - - -  - - | |  | | - -
 
// 여기까지만 보면, dp[4]는 dp[2]를 양옆으로 이어붙인 경우와 새로운 도형(*******) 2개가 추가된 형태라는 것을 알 수 있음
// 따라서 이어지는 dp는 기본적으로 이전 dp 옆에 dp[2]의 경우 3가지 중 하나를 추가하는 셈이 되므로 dp[n] = dp[n - 2] * 3이 기본적으로 적용됨
// 이러한 방식으로 계속 그리다보면, 다음 dp에 도달할 때마다 새로운 도형이 2가지씩 생기는 것을 볼 수 있음 - 그리고 그 형태는 *******와 같음
// n에서 처음 등장하는 오리지널 도형 2종과, dp[n - 2]에서 새롭게 dp[2]의 3가지 경우를 채우는 수, 그리고 dp[n - 4]부터 dp[0]까지 오리지널 도형 2개를 이용해 채우는 것까지 생각해야 함
// 결과적으로 점화식은 위와 같은 형태가 됩니다