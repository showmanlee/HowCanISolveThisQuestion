// FYI
// https://www.acmicpc.net/problem/17863

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	cout << (s.substr(0, 3) == "555" ? "YES" : "NO") << '\n';
}

// 전화번호가 555로 시작하는지 판별하기

// 첫 3글자가 555인가요?