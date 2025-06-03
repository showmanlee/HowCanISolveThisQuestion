// СИМЕТРИЧНИ ЧИСЛА
// https://www.acmicpc.net/problem/31244

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	if (a == c) {
		cout << a << b << c;
	} else if (b == c) {
		cout << a << b << c << a;
	} else {
		cout << a << b << c << b << a;
	}
	cout << '\n';
}

// 주어진 3개의 숫자가 차례로 주어지는 숫자 중 가장 작은 대칭수 구하기