// 인생 점수
// https://www.acmicpc.net/problem/15351

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	for (int t = 0; t < n; t++) {
		string s;
		getline(cin, s);
		int res = 0;
		for (char c : s) {
			if (isupper(c)) {
				res += c - 'A' + 1;
			}
		}
		if (res == 100) {
			cout << "PERFECT LIFE\n";
		} else {
			cout << res << '\n';
		}
	}
}

// 주어진 대문자 문자열에서 A=1, B=2...로 계산한 점수의 합을 출력하되, 100점이면 대신 PERFECT LIFE를 출력하기

// 그렇게 해주면 될듯?