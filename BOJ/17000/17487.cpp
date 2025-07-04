// 타자 연습
// https://www.acmicpc.net/problem/17487

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string lefty = "qwertyasdfgzxcvb";

bool side(int i) {
	char c = 'a' + i;
	if (lefty.find(c) != string::npos) {
		return true;
	} else {
		return false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	int l = 0, r = 0, m = 0;
	for (char c : s) {
		if (isupper(c)) {
			if (side(c - 'A')) {
				l++;
			} else {
				r++;
			}
			m++;
		} else if (islower(c)) {
			if (side(c - 'a')) {
				l++;
			} else {
				r++;
			}
		} else {
			m++;
		}
	}
	while (m > 0) {
		if (l > r) {
			r++;
		} else {
			l++;
		}
		m--;
	}
	cout << l << ' ' << r << '\n';
}

// 주어진 문자열을 입력하는데 쳐야 하는 왼손과 오른손의 횟수 구하기