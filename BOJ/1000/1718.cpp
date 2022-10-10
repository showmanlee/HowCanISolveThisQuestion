// 암호
// https://www.acmicpc.net/problem/1718

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, t;
	getline(cin, s);
	getline(cin, t);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			cout << ' ';
			continue;
		}
		int p = s[i] - 'a';
		p = (p + 26 - (t[i % t.length()] - 'a' + 1)) % 26;
		cout << (char)('a' + p);
	}
	cout << '\n';
}

// 주어진 소문자 평서문을 암호화 키를 이용해 암호화하기

// 공백은 그대로 출력하고, 나머지 소문자는 대응되는 글자의 알파벳 순서만큼 뺸 순서의 글자 출력