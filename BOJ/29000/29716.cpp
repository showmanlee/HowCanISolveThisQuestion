// 풀만한문제
// https://www.acmicpc.net/problem/29716

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int j, n;
	cin >> j >> n;
	int res = 0;
	cin.ignore();
	for (int t = 0; t < n; t++) {
		string s;
		getline(cin, s);
		int p = 0;
		for (char c : s) {
			if (isupper(c)) {
				p += 4;
			} else if (c == ' ') {
				p += 1;
			} else {
				p += 2;
			}
 		}
		if (p <= j) {
			res++;
		}
	}
	cout << res << '\n';
}

// 대문자는 4, 공백은 1, 나머지는 2점으로 계산해서 공백 있는 문자열의 점수를 계산할 때, 점수가 j 이하인 문자열의 개수 구하기