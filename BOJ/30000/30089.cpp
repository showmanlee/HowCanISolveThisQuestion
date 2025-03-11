// 새로운 문자열 만들기
// https://www.acmicpc.net/problem/30089

#include <iostream>
#include <string>
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
		for (int i = 0; i < s.length(); i++) {
			bool pass = true;
			for (int j = 0; j < s.length() - i; j++) {
				if (s[i + j] != s[s.length() - 1 - j]) {
					pass = false;
					break;
				}
			}
			if (pass) {
				string ss = s;
				reverse(ss.begin(), ss.end());
				s += ss.substr(s.length() - i);
				cout << s << '\n';
				break;
			}
		}
	}
}

// 주어진 문자열을 거꾸로 이어붙여 팰린드롬 만들기