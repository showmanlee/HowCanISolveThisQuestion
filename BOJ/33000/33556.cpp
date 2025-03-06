// Java String Equals
// https://www.acmicpc.net/problem/33556

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	if (a == "null") {
		cout << "NullPointerException\nNullPointerException\n";
	} else if (b == "null") {
		cout << "false\nfalse\n";
	} else {
		cout << (a == b ? "true" : "false") << '\n';
		for (char& c : a) {
			if (isupper(c)) {
				c = tolower(c);
			}
		}
		for (char& c : b) {
			if (isupper(c)) {
				c = tolower(c);
			}
		}
		cout << (a == b ? "true" : "false") << '\n';
	}
}

// 주어진 문자열의 대소문자 구분 동일, 대소문자 무시 동일 여부 구하기 - 단 첫 문자열이 null인 경우 에러 띄위기