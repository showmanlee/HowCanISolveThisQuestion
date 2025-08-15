// Numbersrebmun
// https://www.acmicpc.net/problem/4141

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

char toDigit(char c) {
	if (islower(c)) {
		c = toupper(c);
	}
	if ('A' <= c && c <= 'C') {
		return '2';
	} else if ('D' <= c && c <= 'F') {
		return '3';
	} else if ('G' <= c && c <= 'I') {
		return '4';
	} else if ('J' <= c && c <= 'L') {
		return '5';
	} else if ('M' <= c && c <= 'O') {
		return '6';
	} else if ('P' <= c && c <= 'S') {
		return '7';
	} else if ('T' <= c && c <= 'V') {
		return '8';
	} else if ('W' <= c && c <= 'Z') {
		return '9';
	}
	return '0';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			s[i] = toDigit(s[i]);
		}
		bool res = true;
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - i - 1]) {
				res = false;
				break;
			}
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 주어진 알파벳 문장을 전화번호로 바꿨을 때 팰린드롬이 되는지 판정하기