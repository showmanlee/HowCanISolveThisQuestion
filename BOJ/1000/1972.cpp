// 놀라운 문자열
// https://www.acmicpc.net/problem/1972

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		cin >> s;
		if (s == "*") {
			break;
		}
		int n = s.length();
		bool res = true;
		for (int i = 0; i < n - 2; i++) {
			map<string, int> v;
			for (int j = 0; j < n - i - 1; j++) {
				string ss;
				ss += s[j];
				ss += s[j + i + 1];
				v[ss]++;
				if (v[ss] > 1) {
					res = false;
					break;
				}
			}
			if (!res) {
				break;
			}
		}
		cout << s << " is " << (res ? "" : "NOT ") << "surprising.\n";
	}
}

// 대문자 문자열에서 두 문자를 순서대로 선택해 만들 수 있는 모든 문자열에서 같은 간격으로 선택한 문자열들이 모두 고유한지 판정하기