// ТАБЕЛА
// https://www.acmicpc.net/problem/31245

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b, c;
	cin >> a >> b >> c;
	string res = a;
	if (a.back() == b.front()) {
		res += '\'';
		res += b.substr(1);
	} else {
		res += b;
	}
	if (b.back() == c.front()) {
		res += '\'';
		res += c.substr(1);
	} else {
		res += c;
	}
	cout << res << '\n';
}

// 주어진 수 3개를 이어붙일 때 이어붙인 부분의 숫자가 중복되면 압축하기