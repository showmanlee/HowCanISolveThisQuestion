// 더블팰린드롬
// https://www.acmicpc.net/problem/32357

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		bool pass = true;
		for (int j = 0; j < s.length() / 2; j++) {
			if (s[j] != s[s.length() - j - 1]) {
				pass = false;
				break;
			}
		}
		if (pass) {
			cnt++;
		}
	}
	int res = cnt * (cnt - 1);
	cout << res << '\n';
}

// 짝수 길이의 문자열 사이에 다른 문자열을 넣어 팰린드롬을 만들 수 있는 경우의 수 구하기