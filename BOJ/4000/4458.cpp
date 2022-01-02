// 첫 글자를 대문자로
// https://www.acmicpc.net/problem/4458

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		string s;
		getline(cin, s);
		if (i == 0)
			continue;
		if (islower(s[0]))
			s[0] = toupper(s[0]);
		cout << s << '\n';
	}
}

// 문자열의 첫 글자를 대문자로
// 각 단어의 첫 글자를 바꾸지 말고, 그냥 첫 글자만 바꾸자
// 첫 글자는 알파벳이나, 대문자일 수 있음 - 그럼 안 바꾸고
// getline으로 입력 받으면 첫 줄이 공백이 되니까 그건 흘려주고 시작하기