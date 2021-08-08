// 문자열
// https://www.acmicpc.net/problem/9086

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << s[0] << s[s.length() - 1] << '\n';
	}
}

// 주어진 문자열의 첫 글자와 마지막 문자 출력하기

// 말 그대로 그렇게 출력해주면 됨 - 마지막 글자는 length - 1