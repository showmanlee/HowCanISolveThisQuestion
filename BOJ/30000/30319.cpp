// Advance to Taoyuan Regional
// https://www.acmicpc.net/problem/30319

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int y = stoi(s.substr(0, 4));
	int m = stoi(s.substr(5, 2));
	int d = stoi(s.substr(8, 2));
	bool res = true;
	if (y > 2023) {
		res = false;
	} else if (y == 2023) {
		if (m > 9) {
			res = false;
		} else if (m == 9) {
			if (d > 16) {
				res = false;
			}
		}
	}
	cout << (res ? "GOOD" : "TOO LATE") << '\n';
}

// 주어진 날짜가 2023년 10월 21일의 35일 전보다 빠른지 구하기