// Hex Code
// https://www.acmicpc.net/problem/11784

#include <iostream>
#include <algorithm>
using namespace std;

int trans(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else {
		return c - 'A' + 10;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	while (cin >> s) {
		string res;
		for (int i = 0; i < s.length(); i += 2) {
			char c = trans(s[i]) * 16 + trans(s[i + 1]);
			res += c;
		}
		cout << res << '\n';
	}
}

// 주어진 헥스코드 문자열을 아스키코드 문자열로 바꾸기