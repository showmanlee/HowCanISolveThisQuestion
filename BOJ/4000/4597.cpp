// 패리티
// https://www.acmicpc.net/problem/4597

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		cin >> s;
		if (s == "#") {
			break;
		}
		int cnt = 0;
		for (char c : s) {
			if (c == '1') {
				cnt++;
			}
		}
		bool p = cnt % 2 == 1;
		cout << s.substr(0, s.length() - 1);
		if (s.back() == 'e') {
			cout << (p ? 1 : 0);
		}
		else {
			cout << (p ? 0 : 1);
		}
		cout << '\n';
	}
}

// 1의 개수에 따른 홀수(o)/짝수(e) 패리티가 마지막 숫자를 대체한 비트가 주어질 때, 원래 비트 출력하기

// 그 전까지 나온 1의 개수를 센 뒤, 센 홀짝과 oe를 보고 0/1 찍어주기