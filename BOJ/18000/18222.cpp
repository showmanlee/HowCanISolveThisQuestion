// 투에-모스 문자열
// https://www.acmicpc.net/problem/18222

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

long long f(long long n) {
	if (n == 1) {
		return 0;
	}
	long long p = 1;
	while (p * 2 < n) {
		p *= 2;
	}
	long long ret = f(n - p) == 0 ? 1 : 0;
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	cout << f(n) << '\n';
}

// 투에-모스 수열의 n번째 숫자 구하기