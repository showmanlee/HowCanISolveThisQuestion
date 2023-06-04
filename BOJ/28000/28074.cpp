// 모비스
// https://www.acmicpc.net/problem/28074

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string v;
	cin >> v;
	bool m = false, o = false, b = false, i = false, s = false;
	for (char c : v) {
		if (c == 'M') {
			m = true;
		} else if (c == 'O') {
			o = true;
		} else if (c == 'B') {
			b = true;
		} else if (c == 'I') {
			i = true;
		} else if (c == 'S') {
			s = true;
		}
	}
	cout << (m && o && b && i && s ? "YES" : "NO") << '\n';
}

// 주어진 대문자 문자열에 M, O, B, I, S가 있는지 판정하기

// 문자 돌면서 확인해보면 되지요