// Enigma
// https://www.acmicpc.net/problem/16446

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int res = 0;
	for (int i = 0; i < a.length() - b.length() + 1; i++) {
		bool fail = false;
		for (int j = 0; j < b.length(); j++) {
			if (a[i + j] == b[j]) {
				fail = true;
				break;
			}
		}
		if (!fail) {
			res++;
		}
	}
	cout << res << '\n';
}

// 문자열 a의 부분 문자열 중 b와 글자가 겹치지 않는 경우 구하기