// 거울, 오! 거울
// https://www.acmicpc.net/problem/4740

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		getline(cin, s);
		if (s == "***") {
			break;
		}
		for (int i = s.length() - 1; i >= 0; i--) {
			cout << s[i];
		}
		cout << '\n';
	}
}

// 공백이 포함된 주어진 문자열을 거꾸로 출력하기

// getline으로 받아서 역순 인덱스대로 출력하면 됩니다!