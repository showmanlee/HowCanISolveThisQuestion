// :chino_shock:
// https://www.acmicpc.net/problem/27310

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = s.length();
	for (char c : s) {
		if (c == ':') {
			res++;
		} else if (c == '_') {
			res += 5;
		}
	} 
	cout << res << '\n';
}

// : 두 개 사이 소문자나 _로 구성된 문자열에서 (전체 길이) + (:의 개수) + (_의 개수) * 5 구하기

// 문자열 받고 글자들 보면서 점수 누적시키기