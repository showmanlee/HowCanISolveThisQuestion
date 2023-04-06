// 특별한 학교 이름
// https://www.acmicpc.net/problem/27889

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	if (s == "NLCS") {
		cout << "North London Collegiate School\n";
	} else if (s == "BHA") {
		cout << "Branksome Hall Asia\n";
	} else if (s == "KIS") {
		cout << "Korea International School\n";
	} else if (s == "SJA") {
		cout << "St. Johnsbury Academy\n";
	}
}

// 학교의 약칭이 주어졌을 때, 학교의 풀네임 출력하기

// 4개 중 하나만 말하면 됨 - 조건문