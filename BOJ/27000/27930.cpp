// 당신은 운명을 믿나요?
// https://www.acmicpc.net/problem/27930

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string korea = "KOREA"; string yonsei = "YONSEI";
	int ki = 0, yi = 0;
	for (char c : s) {
		if (c == korea[ki]) {
			ki++;
			if (ki == 5) {
				cout << korea << '\n';
				break;
			}
		}
		if (c == yonsei[yi]) {
			yi++;
			if (yi == 6) {
				cout << yonsei << '\n';
				break;
			}
		}
	}
}

// 주어진 대문자 문자열을 순회하여 KOREA, YONSEI가 순서대로 나오는지 확인하기

// 문자열 순회로 확인해봅니다