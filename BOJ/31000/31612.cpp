// 画数数え (Stroke Count)
// https://www.acmicpc.net/problem/31612

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
	int res = 0;
	for (char c : s) {
		if (c == 'o') {
			res += 1;
		} else {
			res += 2;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열을 쓰는데 필요한 획 수 구하기