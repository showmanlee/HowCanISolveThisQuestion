// driip
// https://www.acmicpc.net/problem/23627

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	bool res = (s.length() >= 5 && s.substr(s.length() - 5, 5) == "driip");
	cout << (res ? "" : "not ") << "cute" << '\n';
}

// 주어진 문자열이 driip으로 끝나는지 판별하기

// 문자열의 길이가 5글자 이상인 경우, 끝부분이 driip인지 확인해보기