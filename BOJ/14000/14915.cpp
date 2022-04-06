// 진수 변환기
// https://www.acmicpc.net/problem/14915

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	string res;
	while (n > 0) {
		int p = n % m;
		if (p < 10) {
			res = (char)('0' + p) + res;
		}
		else {
			res = (char)('A' + p - 10) + res;
		}
		n /= m;
	}
	if (n == 0 && res == "") {
		res = "0";
	}
	cout << res << '\n';
}

// 10진수 n을 m진수로 변환하기

// 평소에 하던 문자열 기반 m진수 변환을 수행하면 된다
// n 입력 범위에 0도 포함됨에 주의