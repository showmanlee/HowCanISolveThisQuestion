// Alphabetic Shift
// https://www.acmicpc.net/problem/33528

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	cout << s << '\n';
	for (int i = 25; i >= 1; i--) {
		for (char c : s) {
			int p = (c - 'A' + i) % 26;
			char cc = 'A' + p;
			cout << cc;
		}
		cout << '\n';
	}
}

// 주어진 대문자 문자열의 글자들을 한 글자씩 내리는 모든 경우 출력하기