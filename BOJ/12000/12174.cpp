// #include <Google I/O.h>
// https://www.acmicpc.net/problem/12174

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int b;
		cin >> b;
		string s;
		cin >> s;
		cout << "Case #" << t << ": ";
		for (int i = 0; i < b; i++) {
			int p = 128;
			char c = 0;
			for (int j = 0; j < 8; j++) {
				c += p * (s[i * 8 + j] == 'I' ? 1 : 0);
				p /= 2;
			}
			cout << c;
		}
		cout << '\n';
	}
} 

// 일반 문자열을 비트로 변환한 결과가 I와 O로 찍힌 문자열로 원래 문자열 출력하기

// 비트 문자열 전체 길이 / 8(b)가 주어지므로 이를 이용해 받은 문자열에서 한 바이트를 분리하고, 그 바이트에서 2진수 복구하듯 10진수로 바꾸어 출력하기
// 언제까지? 문자열 끝날 때까지