// 명령 프롬프트
// https://www.acmicpc.net/problem/1032

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	int n;
	string s;
	cin >> n >> s;
	vector<bool> same(s.length(), true);
	for (int i = 1; i < n; i++) {
		string ss;
		cin >> ss;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] != ss[j])
				same[j] = false;
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (same[i])
			cout << s[i];
		else
			cout << '?';
	}
	cout << '\n';
}

// 들어오는 문자열들(길이 같음)에서 해당 위치에 같은 문자가 나온다면 원래 글자, 그렇지 않다면 ? 출력