// 입실 관리
// https://www.acmicpc.net/problem/5524

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char &c : s) {
			c = tolower(c);
		}
		cout << s << '\n';
	}
}

// 주어진 문자열의 대문자를 소문자로 바꾸기

// 바꿉니다