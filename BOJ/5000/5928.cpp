// Contest Timing
// https://www.acmicpc.net/problem/5928

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	int t = 11 * 60 * 24 + 11 * 60 + 11;
	int p = a * 60 * 24 + b * 60 + c;
	int res = p - t;
	if (res < 0) {
		res = -1;
	}
	cout << res << '\n';
}

// 주어진 날짜 시간 분이 11일 11시 11분과 얼마나 차이나는지 구하기