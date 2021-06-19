// ROT13
// https://www.acmicpc.net/problem/11655

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	for (char c : s) {
		if (islower(c))
			cout << char(((c - 'a' + 13) % 26) + 'a');
		else if (isupper(c))
			cout << char(((c - 'A' + 13) % 26) + 'A');
		else
			cout << c;
	}
	cout << '\n';
}

// 알파벳을 13글자씩 밀어서 출력한 문자열 출력하기

// 해당 글자가 대문자인지 소문자인지 확인하여, 해당되는 'A'를 빼고 13을 더해서 나머지 연산한 것에 'A'를 더한 문자를 출력
// 둘 다 아니면 그냥 그대로 출력