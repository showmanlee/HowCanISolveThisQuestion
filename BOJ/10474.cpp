// 일반 화학 실험
// https://www.acmicpc.net/problem/10474

#include <iostream>
using namespace std;

int main(void) {
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		int c = a / b;
		a %= b;
		cout << c << ' ' << a << " / " << b << '\n';
	}
}

// 가분수를 대분수로 만들기