// 무지개 만들기
// https://www.acmicpc.net/problem/30403

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int idx(char c) {
	if (isupper(c)) {
		return c - 'A';
	} else if (islower(c)) {
		return c - 'a' + 26;
	}
	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<bool> cnt(52);
	for (char c : s) {
		cnt[idx(c)] = true;
	}
	bool upper = cnt[idx('R')] && cnt[idx('O')] && cnt[idx('Y')] && cnt[idx('G')] && cnt[idx('B')] && cnt[idx('I')] && cnt[idx('V')];
	bool lower = cnt[idx('r')] && cnt[idx('o')] && cnt[idx('y')] && cnt[idx('g')] && cnt[idx('b')] && cnt[idx('i')] && cnt[idx('v')];
	string res = (upper ? (lower ? "YeS" : "YES") : (lower ? "yes" : "NO!"));
	cout << res << '\n';
}

// 대소문자 문자열에서 대소문자 ROYGBIV가 있는지 확인하기