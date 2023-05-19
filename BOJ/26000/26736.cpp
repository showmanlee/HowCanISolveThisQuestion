// Wynik meczu
// https://www.acmicpc.net/problem/26736

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int a = 0, b = 0;
	for (char c : s) {
		if (c == 'A') {
			a++;
		} else {
			b++;
		}
	}
	cout << a << " : " << b << '\n';
}

// A와 B로 구성된 문자열에서 A와 B의 개수 구하기

// 직접 세서 구해봅시다