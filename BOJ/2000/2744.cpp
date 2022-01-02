// 대소문자 바꾸기
// https://www.acmicpc.net/problem/2744

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	for (char c : s) {
		if (isupper(c))
			cout << char(tolower(c));
		else
			cout << char(toupper(c));
	}
	cout << '\n';
}

// 알파벳으로 구성된 문자열의 대소문자를 서로 바꿔 출력하기
// 그저 하면 됩니다 - cctype의 힘을 빌려... (굳이 안 빌려도 된다마는)