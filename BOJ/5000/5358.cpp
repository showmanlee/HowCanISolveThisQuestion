// Football Team
// https://www.acmicpc.net/problem/5358

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (getline(cin, s)) {
		for (char& c : s) {
			if (c == 'i') {
				c = 'e';
			} else if (c == 'e') {
				c = 'i';
			}
			if (c == 'I') {
				c = 'E';
			} else if (c == 'E') {
				c = 'I';
			}
		}
		cout << s << '\n';
	}
}

// 주어진 문자열에서 i와 e를 서로 바꾸기

// 그대로 받고 바꿔주면 됩니다...
