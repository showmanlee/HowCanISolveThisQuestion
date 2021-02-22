// 싱기한 네자리 숫자
// https://www.acmicpc.net/problem/6679

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	for (int i = 1000; i <= 9999; i++) {
		int t = 0, d = 0, h = 0;
		int p = i;
		while (p > 0) {
			t += p % 10;
			p /= 10;
		}
		p = i;
		while (p > 0) {
			d += p % 12;
			p /= 12;
		}
		p = i;
		while (p > 0) {
			h += p % 16;
			p /= 16;
		}
		if (t == d && d == h)
			cout << i << '\n';
	}
}

// 네자리 10진수를 10진수, 12진수, 16진수로 표현할 때 각 자릿수의 합이 모두 같은 수를 모두 출력하기
// X진수 만들기 코드 활용, 각 자리를 모두 더해보자