// 팰린드롬 만들기
// https://www.acmicpc.net/problem/1254

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		string ss = s.substr(i);
		bool p = true;
		for (int j = 0; j < ss.length() / 2; j++) {
			if (ss[j] != ss[ss.length() - j - 1]) {
				p = false;
				break;
			}
		}
		if (p) {
			res = s.length() + i;
			break;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열 뒤에 문자를 붙여 만들 수 있는 팰린드롬 최소 길이 출력하기