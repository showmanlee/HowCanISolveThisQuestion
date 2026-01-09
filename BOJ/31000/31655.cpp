// International Dates
// https://www.acmicpc.net/problem/31655

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int a = stoi(s.substr(0, 2));
	int b = stoi(s.substr(3, 2));
	string res;
	if (a > 12) {
		res = "EU";
	} else if (b > 12) {
		res = "US";
	} else {
		res = "either";
	}
	cout << res << '\n';
}

// 두 수 중 가장 큰 수 * 2를 규칙에 맞게 출력하기