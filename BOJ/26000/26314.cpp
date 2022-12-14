// Vowel Count
// https://www.acmicpc.net/problem/26314

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		cin >> s;
		int a = 0, b = 0;
		for (char c : s) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				a++;
			} else {
				b++;
			}
		}
		cout << s << '\n' << (a > b ? 1 : 0)  << '\n';
	}
}

// 주어진 소문자 문자열에서 모음이 자음보다 많은지 판별하기

// 문자열 받고, 자음/모음 개수 세서 찍으면 되지요...