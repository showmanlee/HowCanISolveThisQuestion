// Sõnasnäki lahendamine
// https://www.acmicpc.net/problem/32729

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string ss;
	cin >> ss;
	vector<int> v(26);
	for (char c : ss) {
		v[c - 'a']++;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<int> cnt(26);
		bool pass = true;
		for (char c : s) {
			cnt[c - 'a']++;
			if (cnt[c - 'a'] > v[c - 'a']) {
				pass = false;
				break;
			}
		}
		if (pass) {
			cout << s << '\n';
		}
	}
}

// 주어진 문자열의 알파벳으로 주어지는 문자열들 중 만들 수 있는 문자열 출력하기