// 너의 이름은 몇 점이니?
// https://www.acmicpc.net/problem/15813

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		res += c - 'A' + 1;
	}
	cout << res << '\n';
}

// 주어진 대문자 문자열을 A = 1, B = 2, C = 3...처럼 점수를 계산하여 출력하기

// 문자열 받고 계산하면 됩니다 - 아니면 문자 단위로 받으며 실시간 연산하거나...