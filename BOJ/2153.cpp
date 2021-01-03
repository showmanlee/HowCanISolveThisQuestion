// 소수 단어
// https://www.acmicpc.net/problem/2153

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
	int p = 0;
	string s;
	cin >> s;
	for (char c : s) {
		if (c >= 'a' && c <= 'z')
			p += (c - 'a' + 1);
		else if (c >= 'A' && c <= 'Z')
			p += (c - 'A' + 27);
	}
	bool res = true;
	for (int i = 2; i <= sqrt(p) + 1; i++) {
		if (p % i == 0)
			res = false;
		if (!res)
			break;
	}
	cout << (res ? "It is a prime word.\n" : "It is not a prime word.\n");
}

// 주어지는 알파벳들을 규칙에 맞게 숫자로 바꿔 더한 값이 소수인가?
// 수를 얻는 방식만 다를 뿐 같은 소수 판정 문제