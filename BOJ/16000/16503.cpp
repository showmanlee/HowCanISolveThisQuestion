// 괄호 없는 사칙연산
// https://www.acmicpc.net/problem/16503

#include <iostream>
using namespace std;

int calc(int a, char x, int b) {
	if (x == '+')
		return a + b;
	else if (x == '-')
		return a - b;
	else if (x == '*')
		return a * b;
	else
		return a / b;
}

int main(void) {
	int a, b, c;
	char x, y;
	cin >> a >> x >> b >> y >> c;
	int r = calc(a, x, calc(b, y, c));
	int e = calc(calc(a, x, b), y, c);
	if (r > e)
		cout << e << '\n' << r << '\n';
	else

		cout << r << '\n' << e << '\n';
}

// 피연산자가 3개(= 연산자가 2개)인 사칙연산에서 두 가지 연산순서에 따른 결과 출력하기
// 계산 과정을 함수로 만들어서 연산 순서를 구현해보자