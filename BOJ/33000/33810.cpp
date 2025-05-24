// SciComLove (2025)
// https://www.acmicpc.net/problem/33810

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string t = "SciComLove";
	int res = 0;
	for (int i = 0; i < 10; i++) {
		if (s[i] != t[i]) {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열이 "SciComLove"와 몇 글자가 다른지 출력하기