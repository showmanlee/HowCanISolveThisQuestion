// 비밀번호 발음하기
// https://www.acmicpc.net/problem/4659

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	string vowel = "aeiou";
	while (true) {
		cin >> s;
		if (s == "end")
			break;
		int combo = 0;
		int prev = 0;
		bool shown = false;
		bool fail = false;
		for (int i = 0; i < s.length(); i++) {
			int cur = (vowel.find(s[i]) == string::npos ? 1 : 2);
			if (cur == 2)
				shown = true;
			if (prev == cur)
				combo++;
			else
				combo = 1;
			if (combo == 3) 
				fail = true;
			if (i != 0 && s[i] != 'e' && s[i] != 'o' && s[i] == s[i - 1]) 
				fail = true;
			if (fail)
				break;
			prev = cur;
		}
		if (!shown)
			fail = true;
		cout << "<" << s << "> is " << (fail ? "not acceptable." : "acceptable.") << '\n';
	}
}

// 주어지는 소문자 문자열이 다음 조건을 만족하는가?
// - 모음이 하나 이상 포함되어야 한다
// - 모음 또는 자음이 연속으로 3개 이상 등장하면 안 된다
// - e, o를 제외한 같은 글자가 연속으로 등장하면 안 된다

// 판정해야 하는 부분 - 모음 등장 여부, 자음/모음 연속 등장 여부, 동일 글자 연속 등장 여부
// 조건문과 변수를 이용해 문자열을 순회하며 적절하게 판정하기