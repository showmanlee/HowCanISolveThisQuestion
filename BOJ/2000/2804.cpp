// 크로스워드 만들기
// https://www.acmicpc.net/problem/2804

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int aa = -1, bb = -1;
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				aa = i;
				bb = j;
				break;
			}
		}
		if (aa != -1) {
			break;
		}
	}

	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			if (i == bb && j == aa) {
				cout << a[j];
			} else if (i == bb) {
				cout << a[j];
			} else if (j == aa) {
				cout << b[i];
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}
}

// 두 문자열에서 겹치는 문자가 교차되는 크로스워드 만들기