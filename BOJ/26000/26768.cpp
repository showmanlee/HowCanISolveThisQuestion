// H4x0r
// https://www.acmicpc.net/problem/26768

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	for (char& c : s) {
		if (c == 'a') {
			c = '4';
		} else if (c == 'e') {
			c = '3';
		} else if (c == 'i') {
			c = '1';
		} else if (c == 'o') {
			c = '0';
		} else if (c == 's') {
			c = '5';
		}
	}
	cout << s << '\n';
}

// 주어진 문자열에서 aeios를 43105로 바꾸기

// 역시 받고 글자 순회하면서 바꿔주면 됩니다
