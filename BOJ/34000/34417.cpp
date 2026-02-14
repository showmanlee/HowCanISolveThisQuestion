// Alphabet Soup
// https://www.acmicpc.net/problem/34417

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> v(26);
	int res = 26;
	string s;
	cin >> s;
	for (char c : s) {
		if (!v[c - 'A']) {
			v[c - 'A'] = true;
			res--;
		}
	}
	if (res == 0) {
		cout << "Alphabet Soup!\n";
	} else {
		for (int i = 0; i < 26; i++) {
			if (!v[i]) {
				cout << (char)(i + 'A');
			}
		}
		cout << '\n';
	}
}

// 주어진 대문자 문자열에서 모든 알파벳이 있는지 확인하고, 없다면 없는 거 출력하기