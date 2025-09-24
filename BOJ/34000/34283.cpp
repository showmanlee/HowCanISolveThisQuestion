// Certainly
// https://www.acmicpc.net/problem/34283

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	int res = 0;
	for (int i = 0; i < s.length() - 8; i++) {
		string ss = s.substr(i, 9);
		if (ss == "certainly") {
			res++;
		}
	}
	cout << res << '\n';
}

// 소문자 문자열에 있는 "certainly"의 개수 구하기