// 니모를 찾아서
// https://www.acmicpc.net/problem/10173

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		getline(cin, s);
		if (s == "EOI") {
			break;
		}
		for (char& c : s) {
			if (isupper(c)) {
				c = tolower(c);
			}
		}
		bool res = false;
		for (int i = 0; i < s.length() - 3; i++) {
			if (s.substr(i, 4) == "nemo") {
				res = true;
				break;
			}
		}
		cout << (res ? "Found" : "Missing") << '\n';
	}
}


// 주어진 문자열에서 대소문자 관계없이 nemo 찾기

// 문자열 길이가 길지 않으므로 실제로 찾아보면 된다