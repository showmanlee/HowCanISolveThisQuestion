// 모음의 개수
// https://www.acmicpc.net/problem/10987

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = 0;
	for (char c : s)
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			res++;
	cout << res << '\n';
}

// 소문자로 구성된 문자열에 있는 모음의 개수는?
// 직접 세보는 수밖에