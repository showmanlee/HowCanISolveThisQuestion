// 호반우가 학교에 지각한 이유 1
// https://www.acmicpc.net/problem/30468

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	n *= 4;
	int res = 0;
	if ((a + b + c + d) < n) {
		res = n - (a + b + c + d);
	}
	cout << res << '\n';
}

// 주어진 네 수의 평균을 n 이상으로 만들기 위해 더해야 하는 값 구하기