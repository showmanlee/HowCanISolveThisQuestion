// 태권도와 복싱을 합한 운동
// https://www.acmicpc.net/problem/33937

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isVowel(char c) {
	if (c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u') {
		return true;
	}
 	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	string aa, bb;
	for (int i = 0; i < a.length(); i++) {
		if (i != a.length() - 1 && isVowel(a[i]) && !isVowel(a[i + 1])) {
			aa = a.substr(0, i + 1);
			break;
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (i != b.length() - 1 && isVowel(b[i]) && !isVowel(b[i + 1])) {
			bb = b.substr(0, i + 1);
			break;
		}
	}
 	if (aa.empty() || bb.empty()) {
		cout << "no such exercise\n";
	} else {
		cout << aa << bb << '\n';
	}
}

// 주어진 소문자 문자열의 첫음절만 따서 만든 문자열 출력하기