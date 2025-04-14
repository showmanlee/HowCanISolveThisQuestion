// 치매예방수칙 3.3.3
// https://www.acmicpc.net/problem/33709

#include <iostream>
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
	int res = 0;
	string p;
	for (char c : s) {
		if ('0' <= c && c <= '9') {
			p += c;
		} else {
			res += stoi(p);
			p = "";
		}
	}
	res += stoi(p);
	cout << res << '\n';
}

// 문자열에서 구분자로 구분된 수들의 합 구하기