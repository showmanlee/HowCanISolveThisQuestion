// Word Searching
// https://www.acmicpc.net/problem/9771

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string w;
	cin >> w;
	string s;
	int res = 0;
	cin.ignore();
	while (getline(cin, s)) {
		if (s.length() >= w.length()) {
			int idx = w.length() - 1;
			string ss = s.substr(0, w.length());
			while (true) {
				if (ss == w) {
					res++;
				}
				idx++;
				if (idx >= s.length()) {
					break;
				}
				ss = ss.substr(1) + s[idx];
			}
		}
	}
	cout << res << '\n';
}

// 주어진 문장에서 단어가 나온 횟수 구하기