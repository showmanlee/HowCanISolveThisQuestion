// 간지(干支)
// https://www.acmicpc.net/problem/7572

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	cout << char('A' + ((n + 8) % 12)) << char('0' + ((n + 6) % 10)) << '\n';
}

// 주어지는 연도의 간지 표현을 숫자와 알파벳으로 표현하기
// 갑자년은 A0, 을축년은 B1... 계사(2013)년은 F9
// 갑을병정... 은 숫자, 자축인묘.... 는 알파벳
// 십간의 반환점은 mod 10 = 4, 십이간지의 반환점은 mod 12 = 4
// 따라서 각자에 자리에서 (n - 4) % x 계산한 값을 출력하면 되지만, n이 1부터 주어지기 때문에 대신 (n - 4 + x) % x로 계산해야 함