// 揃った文字 (Matched Letters)
// https://www.acmicpc.net/problem/31616

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	bool res = true;
	for (char c : s) {
		if (c != s[0]) {
			res = false;
			break;
		}
	}
	cout << (res ? "Yes" : "No") << '\n';
}

// 주어진 소문자 문자열이 모두 같은 문자인지 구하기