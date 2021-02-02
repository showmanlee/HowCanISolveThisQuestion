// Java vs C++
// https://www.acmicpc.net/problem/3613

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	bool java = false, cpp = false;
	string res = "";
	for (char c : s) {
		if (c == '_')
			cpp = true;
		if (isupper(c))
			java = true;
	}
	if (!islower(s[0]) || (java && cpp) || s[s.length() - 1] == '_')
		res = "Error!";
	else if (!java && !cpp)
		res = s;
	else {
		res += s[0];
		if (java) {
			for (int i = 1; i < s.length(); i++) {
				if (isupper(s[i])) {
					res += '_';
					res += tolower(s[i]);
				}
				else
					res += s[i];
			}
		}
		else if (cpp) {
			bool underscore = false;
			for (int i = 1; i < s.length(); i++) {
				if (s[i] == '_') {
					if (underscore) {
						res = "Error!";
						break;
					}
					underscore = true;
				}
				else if (underscore) {
					underscore = false;
					res += toupper(s[i]);
				}
				else
					res += s[i];
			}
		}
	}
	cout << res << '\n';
}

// Java 형식 변수명(funcAndIdent)과 C++ 형식 변수명(func_and_ident) 변환하기
// 둘다 아닐 수 있음에 주의(Error!)
// _가 연속으로 등장, _와 대문자가 동시에 등장, 첫 문자가 소문자가 아님, _가 마지막에 등장 등