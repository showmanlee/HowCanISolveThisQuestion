// 창영이의 일기장
// https://www.acmicpc.net/problem/2954

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	string res;
	for (int i = 0; i < s.length(); i++) {
		res += s[i];
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			i += 2;
		}
	}
	cout << res << '\n';
}

// 모음이 등장할 때 그 뒤에 p + 해당 모음을 쓴 소문자 문장을 원문으로 변환하기

// 말인즉 모음이 등장하면 그 뒤의 두 글자는 버려야 한다는 의미
