// CPDU
// https://www.acmicpc.net/problem/33689

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[0] == 'C') {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열들 중 C로 시작하는 문자열 개수 구하기