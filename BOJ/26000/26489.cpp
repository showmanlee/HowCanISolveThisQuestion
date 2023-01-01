// Gum Gum for Jay Jay
// https://www.acmicpc.net/problem/26489

#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	int res = 0;
	while (getline(cin, s)) {
		res++;
	}
	cout << res << '\n';
}

// 입력된 문자열 줄 수 출력하기

// 입력되는 문자열은 "gum gum for jay jay" 뿐 - 공백이 있으므로 getline으로 받기
// 그 외에는 흔한 무한 문자열 입력 핸들 문제