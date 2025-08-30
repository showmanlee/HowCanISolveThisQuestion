// Химия
// https://www.acmicpc.net/problem/29483

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	char prev = ' ';
	int cnt = 0;
	int res = 0;
	for (char c : s) {
		if (isdigit(c)) {
			cnt = cnt * 10 + (c - '0');
		} else {
			if (cnt == 0) {
				cnt = 1;
			}
			if (prev == 'H') {
				res += cnt;
			} else if (prev == 'C') {
				res += 12 * cnt;
			} else if (prev == 'N') {
				res += 14 * cnt;
			} else if (prev == 'O') {
				res += 16 * cnt;
			}
			cnt = 0;
			prev = c;
		}
	}
	if (cnt == 0) {
		cnt = 1;
	}
	if (prev == 'H') {
		res += cnt;
	} else if (prev == 'C') {
		res += 12 * cnt;
	} else if (prev == 'N') {
		res += 14 * cnt;
	} else if (prev == 'O') {
		res += 16 * cnt;
	}
	cout << res << '\n';
}

// 주어진 분자식의 원자량 구하기