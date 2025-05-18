// Vandalism
// https://www.acmicpc.net/problem/33651

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string t = "UAPC";
	for (char c : t) {
		if (s.find(c) == string::npos) {
			cout << c;
		}
	}
	cout << '\n';
}

// UAPC 중 없는 글자 출력하기