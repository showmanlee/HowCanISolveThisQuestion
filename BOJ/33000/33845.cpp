// PNUPC에 한 번도 빠지지 않고 출연한 산지니가 새삼 대단하다고 느껴지네
// https://www.acmicpc.net/problem/33845

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	vector<bool> v(26);
	for (char c : s) {
		v[c - 'a'] = true;
	}
	for (char c : t) {
		if (!v[c - 'a']) {
			cout << c;
		}
	}
	cout << '\n';
}

// 첫번째 문자열에서 나온 문자를 빼고 두번째 문자열 출력하기