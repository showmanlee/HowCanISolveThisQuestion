// キャピタリゼーション (Capitalization)
// https://www.acmicpc.net/problem/18415

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	string res = s;
	for (int i = 0; i < n - 2; i++) {
		if (s.substr(i, 3) == "joi") {
			res[i] = 'J';
			res[i + 1] = 'O';
			res[i + 2] = 'I';
		}
	}
	cout << res << '\n';
}

// 소문자 문자열 속 joi를 대문자로 변환하기