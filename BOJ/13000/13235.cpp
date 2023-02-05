// 팰린드롬
// https://www.acmicpc.net/problem/13235

#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.length();
	bool res = true;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[n - i - 1]) {
			res = false;
			break;
		}
	}
	cout << (res ? "true" : "false") << '\n';
}

// 말 그대로 주어진 문자열이 팰린드롬인지 확인하기

// 언제나 똑같은 팰린드롬 문제