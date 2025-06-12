// 브실이의 띠부띠부씰 컬렉션 🍪
// https://www.acmicpc.net/problem/29713

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cnt(26);
	for (char c : s) {
		cnt[c - 'A']++;
	}
	cnt['R' - 'A'] /= 2;
	cnt['E' - 'A'] /= 2;
	int res = min(min(min(min(cnt['B' - 'A'], cnt['R' - 'A']), min(cnt['O' - 'A'], cnt['N' - 'A'])), min(min(cnt['Z' - 'A'], cnt['E' - 'A']), min(cnt['S' - 'A'], cnt['I' - 'A']))), min(cnt['L' - 'A'], cnt['V' - 'A']));
	cout << res << '\n';
}

// 주어진 대문자 문자열의 글자들로 만들 수 있는 BRONZESILVER의 개수 구하기