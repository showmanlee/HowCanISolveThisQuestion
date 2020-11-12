// 아름다운 수
// https://www.acmicpc.net/problem/2774

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		bool count[10] = { false, };
		cin >> s;
		for (char c : s)
			count[c - '0'] = true;
		int res = 0;
		for (bool b : count)
			res += b ? 1 : 0;
		cout << res << '\n';
	}
}

// 이 수에는 숫자가 몇 종류 나옵니까?