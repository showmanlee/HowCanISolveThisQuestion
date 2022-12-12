// Palindromes
// https://www.acmicpc.net/problem/13774

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		cin >> s;
		if (s == "#") {
			break;
		}
		bool done = false;
		for (int t = 0; t < s.length(); t++) {
			string st;
			for (int i = 0; i < s.length(); i++) {
				if (i != t) {
					st += s[i];
				}
			}
			done = true;
			for (int i = 0; i < st.length() / 2; i++) {
				if (st[i] != st[st.length() - 1 - i]) {
					done = false;
					break;
				}
			}
			if (done) {
				cout << st << '\n';
				break;
			}
		}
		if (!done) {
			cout << "not possible\n";
		}
	}
}

// 주어진 문자열에서 정확히 한 글자를 빼서 팰린드롬을 만들 수 있는지 보고, 있다면 그렇게 만든 팰린드롬 출력하기(여러 개라면 먼저 오는 글자를 지운 경우 우선)

// 이건 직접 해보는 수밖에 없긴 함 - 받아서 하나 빼서 팰린드롬 판별하기...