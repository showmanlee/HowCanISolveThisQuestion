// 8진수, 10진수, 16진수
// https://www.acmicpc.net/problem/11816

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int mode = 0;
	if (s.length() >= 2 && s.substr(0, 2) == "0x") {
		s = s.substr(2);
		mode = 2;
	}
	else if (s[0] == '0') {
		s = s.substr(1);
		mode = 1;
	}
	if (mode == 0)
		cout << s << '\n';
	else {
		int res = 0;
		int p = 1;
		while (s.length() != 0) {
			char c = s[s.length() - 1];
			s.pop_back();
			int t = c - '0';
			if (c >= 'a' && c <= 'f')
				t = c - 'a' + 10;
			res += t * p;
			p *= 8 * mode;
		}
		cout << res << '\n';
	}
}

// 0.. 꼴로 주어지는 8진수, 0x.. 꼴로 주어지는 16진수, 그 외의 형태로 주어지는 10진수를 10진수로 변환하기

// 수는 우선 문자열로 받아준 뒤, 첫 1/2글자를 보고 8진수인지 16진수인지 판별하기
// 만약 10진수라면 입력된 문자열을 그대로 출력하기
// 그렇지 않다면 뒤에서부터 문자를 추출해 자릿수와 곱한 걸 더해서 출력하기