// Count Me In
// https://www.acmicpc.net/problem/11319

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	int n = stoi(s);
	while (n--) {
		getline(cin, s);
		int a = 0, b = 0;
		for (char c : s) {
			if (c != ' ') {
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
					b++;
				}
				else {
					a++;
				}
			}
		}
		cout << a << ' ' << b << '\n';
	}
}

// 주어진 문자열에서 자음과 모음 개수 출력하기

// 문자열 문자 순회하면서 공백이 아닐 때 자음 모음 구분해서 세면 되지