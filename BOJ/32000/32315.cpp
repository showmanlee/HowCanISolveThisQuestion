// Cool Phone Numbers
// https://www.acmicpc.net/problem/32315

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	vector<bool> v(10);
	int res = 0;
	for (char c : s) {
		if (c == '-') {
			continue;
		}
		if (!v[c - '0']) {
			v[c - '0'] = true;
			res++;
		}
	}
	cout << res << '\n';
}

// 전화번호에 있는 서로 다른 숫자의 개수 구하기