// 오타맨 고창영
// https://www.acmicpc.net/problem/2711

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		string s;
		cin >> p >> s;
		p--;
		for (int j = 0; j < s.length(); j++) {
			if (j != p)
				cout << s[j];
		}
		cout << '\n';
	}
}

// 해당 문자만 지운 문자열 출력하기