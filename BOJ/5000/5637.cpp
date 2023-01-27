// 가장 긴 단어
// https://www.acmicpc.net/problem/5637

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, res;
	while (cin >> s) {
		if (s == "E-N-D") {
			break;
		}
		string ss;
		for (char c : s) {
			if (isupper(c) || islower(c) || c == '-') {
				ss += c;
			}
		}
		if (res.length() < ss.length()) {
			res = ss;
		}
	}
	for (char& c : res) {
		if (isupper(c)) {
			c = tolower(c);
		}
	}
	cout << res << '\n';
}

// 주어진 문자열에서 대문자/소문자/'-'로만 구성된 가장 긴 단어 출력하기

// 각 단어를 while로 받아내고, 해당 단어에 적합한 문자들만 뽑은 뒤 길이를 비교해 갱신하기
// 단어를 소문자로 출력해야 함에 주의