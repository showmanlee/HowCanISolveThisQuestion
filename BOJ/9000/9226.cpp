// 도깨비말
// https://www.acmicpc.net/problem/9226

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tpp;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string vowel = "aeiou";
	while (true) {
		string s;
		cin >> s;
		if (s == "#") {
			break;
		}
		for (int i = 0; i < s.length(); i++) {
			if (vowel.find(s[0]) != string::npos) {
				break;
			}
			char c = s[0];
			s = s.substr(1);
			s += c;
		}
		s += "ay";
		cout << s << '\n';
	}
}

// 맨 앞 글자가 모음이 아닐 때까지 맨 앞 글자를 맨 뒤로 보낸 후 뒤에 ay를 붙인 결과 출력하기

// 그렇게 만들어주면 됩니다