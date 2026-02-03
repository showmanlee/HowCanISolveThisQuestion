// 이진수 덧셈
// https://www.acmicpc.net/problem/1252

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	if (s.length() < t.length()) {
		swap(s, t);
	}
	string res;
	int p = 0;
	for (int i = 0; i < s.length(); i++) {
		int b = 0;
		if (i < t.length()) {
			b = t[i] - '0';
		}
		int a = (s[i] - '0') + b + p;
		if (a >= 2) {
			a %= 2;
			p = 1;
		} else {
			p = 0;
		}
		res += (char)('0' + a);
	}
	if (p == 1) {
		res += '1';
	}
	while (res.length() > 1 && res.back() == '0') {
		res.pop_back();
	}
	reverse(res.begin(), res.end());
	cout << res << '\n';
}

// 이진수 서로 더하기