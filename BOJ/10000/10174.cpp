// 팰린드롬
// https://www.acmicpc.net/problem/10174

#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string n;
	getline(cin, n);
	for (int i = 0; i < stoi(n); i++) {
		string s;
		getline(cin, s);
		bool res = true;
		for (int j = 0; j < s.length() / 2; j++) {
			if (tolower(s[j]) != tolower(s[s.length() - 1 - j])) {
				res = false;
				break;
			}
		}
		cout << (res ? "Yes" : "No") << '\n';
	}
}

// 주어진 공백 포함 문자열이 팰린드롬인지 판정하기

// 하면 됩니다... 언제나 했던 것처럼