// Skarpetk
// https://www.acmicpc.net/problem/26742

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int b = 0, c = 0;
	for (char h : s) {
		if (h == 'B') {
			b++;
		} else {
			c++;
		}
	}
	int res = (b / 2) + (c / 2);
	cout << res << '\n';
}

// B와 C가 적힌 문자열의 문자들을 뽑아 같은 글자끼리 만들 수 있는 쌍의 개수 출력하기

// 두 글자의 수를 세고, 2로 나눈 후 서로 더한다