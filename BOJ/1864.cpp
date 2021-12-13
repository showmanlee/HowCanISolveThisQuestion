// 문어 숫자
// https://www.acmicpc.net/problem/1864

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int convert(char c) {
	if (c == '-')
		return 0;
	if (c == '\\')
		return 1;
	if (c == '(')
		return 2;
	if (c == '@')
		return 3;
	if (c == '?')
		return 4;
	if (c == '>')
		return 5;
	if (c == '&')
		return 6;
	if (c == '%')
		return 7;
	if (c == '/')
		return -1;
	return -2;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		cin >> s;
		if (s == "#") {
			break;
		}
		int n = 0;
		int p = 1;
		while (!s.empty()) {
			n += convert(s.back()) * p;
			s.pop_back();
			p *= 8;
		}
		cout << n << '\n';
	}
}

// 숫자 -1~7을 기호로 쓰는 8진수 체계가 있을 때, 이를 십진수로 변환하여 출력하기

// 출력하면 됩니다 - 뒤에서부터 하나씩
// 기호와 -1만 있지, 일반적인 8진수 변환 문제와 같음