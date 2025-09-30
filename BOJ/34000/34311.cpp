// QWERTY
// https://www.acmicpc.net/problem/34311

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	string s;
	getline(cin, s);
	string trans = "qwertyuiopasdfghjklzxcvbnm";
	string res;
	for (char c : s) {
		if (c == ' ') {
			res += c;
		} else {
			res += trans[c - 'a'];
		}
	}
	cout << res << '\n';
}

// 키보드에서 영어를 알파벳순으로 바꾼 키보드로 친 문자열이 주어질 때, 원래 문장으로 변형하기