// 구멍
// https://www.acmicpc.net/problem/33571

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	string one = "AabDdegOoPpQqR@";
	getline(cin, s);
	int res = 0;
	for (char c : s) {
		if (c == 'B') {
			res += 2;
		} else if (one.find(c) != string::npos) {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열에서 문자로 인해 표시되는 구멍이 몇 개인지 구하기