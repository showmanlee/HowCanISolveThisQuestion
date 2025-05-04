// 비밀번호
// https://www.acmicpc.net/problem/33779

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	bool res = true;
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			res = false;
			break;
		}
	}
	cout << (res ? "beep" : "boop") << '\n';
}

// 주어진 문자열이 팰린드롬인지 구하기