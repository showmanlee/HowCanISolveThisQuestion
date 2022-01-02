// 크로아티아 알파벳
// https://www.acmicpc.net/problem/2941

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		res++;
		if (i < s.length() - 1) {
			if (s[i] == 'c' && (s[i + 1] == '-' || s[i + 1] == '='))
				i++;
			else if (s[i] == 'd' && s[i + 1] == '-')
				i++;
			else if (s[i] == 'l' && s[i + 1] == 'j')
				i++;
			else if (s[i] == 'n' && s[i + 1] == 'j')
				i++;
			else if (s[i] == 's' && s[i + 1] == '=')
				i++;
			else if (s[i] == 'z' && s[i + 1] == '=')
				i++;
		}
		if (i < s.length() - 2 && s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=')
			i += 2;
	}
	cout << res << '\n';
}

// 한 문자씩 순회하면서 합쳐지는 문자들 체크하며 글자 수 세기
// 조건문 길이는 줄일 수 있습니다 - 읽기 힘들어질 뿐