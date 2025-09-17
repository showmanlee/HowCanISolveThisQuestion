// Cheese Touch
// https://www.acmicpc.net/problem/34290

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	string ss;
	for (int i = n; i < t; i += n) {
		ss = string(s.length(), ' ');
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'I') {
				ss[j] = 'I';
				if (j > 0 && s[j - 1] != 'W') {
					ss[j - 1] = 'I';
				}
				if (j < s.length() - 1 && s[j + 1] != 'W') {
					ss[j + 1] = 'I';
				}
			} else if (ss[j] == ' ') {
				ss[j] = s[j];
			}
		}
		s = ss;
	}
	bool res = false;
	for (char c : s) {
		if (c == 'H') {
			res = true;
			break;
		}
	}
	cout << (res ? "CURED" : "ALL INFECTED") << '\n';
}

// 1차원 공간에서 매 n분마다 I가 양옆 H를 감염시킬 때, t분 전에 모두 감염되는지 구하기