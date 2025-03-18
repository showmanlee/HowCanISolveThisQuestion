// Индикатор
// https://www.acmicpc.net/problem/13064

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		string s;
		cin >> s;
		if (s[0] != s[1] || !isdigit(s[0]) || !isdigit(s[1])) {
			continue;
		}
		if (!isdigit(s[2]) || !isdigit(s[3])) {
			continue;
		}
		if (!isupper(s[4])) {
			continue;
		}
		if (!isdigit(s[5]) || !isdigit(s[6]) || !isdigit(s[7])) {
			continue;
		}
		bool res = true;
		for (char c : s) {
			if (c == '0') {
				res = false;
				break;
			}
		}
		if (!res) {
			continue;
		}
		cout << s << '\n';
	}
}

// 주어진 문자열 중 주어진 조건을 만족하는 문자열 출력하기