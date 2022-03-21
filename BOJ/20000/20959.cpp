// Šifra
// https://www.acmicpc.net/problem/20959

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	for (char& c : s) {
		if (c >= 'a' && c <= 'z') {
			c = ' ';
		}
	}
	set<string> dict;
	stringstream ss(s);
	string buffer;
	while (getline(ss, buffer, ' ')) {
		if (buffer != "") {
			dict.insert(buffer);
		}
	}
	cout << dict.size() << '\n';
}

// 소문자와 숫자로 구성된 문자열에 등장하는 정수의 종류 수 구하기

// 문자열의 소문자를 모두 공백으로 만든 후 split을 돌려 나온 수의 종류를 set으로 센다