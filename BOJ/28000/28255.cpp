// 3단 초콜릿 아이스크림
// https://www.acmicpc.net/problem/28255

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		cin >> s;
		int len = (s.length() + 2) / 3;
		string ss = s.substr(0, len);
		string rev = ss;
		reverse(rev.begin(), rev.end());
		string tail = ss.substr(1);
		string tailR = rev.substr(1);
		bool res = (s == ss + rev + ss || s == ss + tailR + ss || s == ss + rev + tail || s == ss + tailR + tail);
		cout << res << '\n';
	}
}

// s' = s의 첫 ceil(s.length() / 3)글자, rev(s') = s' 뒤집기, tail(s') = s' 첫 글자 제거일 때, 문자열 s가 아래의 경우인지 판정하기
// s == s' + rev(s') + s', s == s' + tail(rev(s')) + s', s == s' + rev(s') + tail(s'), s == s' + tail(rev(s')) + tail(s')

// 각각의 변형 형태를 모두 만들어서 직접 비교해봅시다... - 문자열 변형은 쉬우니...