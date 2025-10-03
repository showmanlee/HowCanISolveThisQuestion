// Uddered but not Herd
// https://www.acmicpc.net/problem/20973

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, s;
	cin >> a >> s;
	int idx = 0, cur = 0;
	int res = 1;
	while (cur < s.length()) {
		idx++;
		if (a[idx] == s[cur]) {
			cur++;
		}
		if (idx >= 26) {
			idx = -1;
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 알파벳 숫자대로 순회하며 문자열을 입력할 때 필요한 바퀴 수 구하기