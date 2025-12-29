// 쿠폰 잘 사용하기?
// https://www.acmicpc.net/problem/34995

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s, p;
	cin >> s >> p;
	if (s.length() > p.length()) {
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				s[i] = '9';
			}
		}
	} else if (s.length() < p.length()) {
		s = "-1";
	} else {
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				s[i] = '9';
			}
		}
		bool pass = false;
		for (int i = 0; i < n; i++) {
			if (s[i] > p[i]) {
				pass = true;
				break;
			} else if (s[i] < p[i]) {
				pass = false;
				break;
			}
		}
		if (s == p) {
			pass = true;
		}
		if (!pass) {
			s = "-1";
		}
	}
	cout << s << '\n';
}

// 일부 숫자가 ?로 가려진 정수와 다른 정수와의 비교에서 이상으로 나오게 물음표 채우기