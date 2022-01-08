// Cryptoquote
// https://www.acmicpc.net/problem/2703

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	for (int t = 0; t < n; t++) {
		string s;
		getline(cin, s);
		string crypto;
		getline(cin, crypto);
		for (char c : s) {
			if (c == ' ') {
				cout << c;
			}
			else {
				cout << crypto[c - 'A']; 
			}
		}
		cout << '\n';
	}
}

// 주어진 대문자 문자열을 각 알파벳에 대응하는 복호화 표를 이용해 해독하기

// 주어진 표에 그대로 대응해서 출력하면 됨 - 공백 예외처리만 잘 하면 되지요