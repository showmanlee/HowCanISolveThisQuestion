// 특정 대문자를 소문자로 바꾸기
// https://www.acmicpc.net/problem/26040

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	vector<int> v(26);
	char p;
	while (cin >> p) {
		v[p - 'A'] = true;
	}
	for (char& c : s) {
		if (isupper(c) && v[c - 'A']) {
			c = c - 'A' + 'a';
		}
	}
	cout << s << '\n';
}

// 주어진 문자열에서 특정 대문자들을 소문자로 바꾸기

// 역시 받고 글자 순회하면서 바꿔주면 됩니다
