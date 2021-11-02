// 이 문제는 D2 입니다.
// https://www.acmicpc.net/problem/23303

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	bool res = false;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s.substr(i, 2) == "d2" || s.substr(i, 2) == "D2") {
			res = true;
		}
	}
	cout << (res ? "D2" : "unrated") << '\n';
}

// 주어진 문자열에 D2나 d2가 있는지 판정하기

// 문자열은 여러 단어로 이루어져 있고, d2 또는 D2 사이에는 띄어쓰기가 있어서는 안 되지만 독립된 단어로 표현될 필요는 없음
// 따라서 getline으로 문장을 받고, 두 글자씩 보면서 d2나 D2가 있는지 보기