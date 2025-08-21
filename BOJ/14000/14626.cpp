// ISBN
// https://www.acmicpc.net/problem/14626

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	bool key = false;
	int sum = 0;
	for (int i = 0; i < 13; i++) {
		if (s[i] == '*') {
			key = i % 2 == 1;
		} else {
			sum += (s[i] - '0') * (i % 2 == 1 ? 3 : 1);
		}
	}
	int res = 0;
	if (key) {
		for (int i = 0; i < 10; i++) {
			if ((sum + (i * 3)) % 10 == 0) {
				res = i;
				break;
			}
		}
	} else {
		res = 10 - sum % 10;
	}
	cout << res << '\n';
}

// ISBN에 빈 한 숫자 출력하기