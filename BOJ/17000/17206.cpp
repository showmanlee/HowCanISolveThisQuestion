// 준석이의 수학숙제
// https://www.acmicpc.net/problem/17206

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int> dp(80001);
	for (int i = 1; i <= 80000; i++) {
		dp[i] = dp[i - 1];
		if (i % 3 == 0 || i % 7 == 0)
			dp[i] += i;
	}
	for (int i = 0; i < n; i++)
		cout << dp[v[i]] << '\n';
}

// n 이하의 3의 배수와 7의 배수를 모두 더한 값은?
// 문제 수는 10만 개, n은 8만까지 나올 수 있음 - n^2가 불가능하다는것
// dp 동원하기 - 80000까지 답을 쫙 만들어놓고, 나온 결과 출력하기