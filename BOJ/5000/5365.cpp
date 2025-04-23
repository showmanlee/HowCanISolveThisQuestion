// Decoder
// https://www.acmicpc.net/problem/5365

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
	string res;
	int idx = 1;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (idx > s.length()) {
			res += ' ';
		} else {
			res += s[idx - 1];
		}
		idx = s.length();
	}
	cout << res << '\n';
}

// 주어진 문자열 배열에서 (전 문자열 길이)번째 문자만 뽑아서 문자열 만들기₩	