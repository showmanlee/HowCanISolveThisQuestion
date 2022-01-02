// 이칙연산
// https://www.acmicpc.net/problem/15726

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double a, b, c;
	cin >> a >> b >> c;
	double r1 = a * b / c, r2 = a / b * c;
	cout << (r1 > r2 ? int(r1) : int(r2)) << '\n';
}

// 세 수 사이에 곱셈 기호와 나눗셈 기호를 하나씩 넣어서 만들 수 있는 수 중 가장 큰 값(소수점 버림)은?
// 정수 기반 나눗셈이 아닌 실수 기반 나눗셈 + 버림임에 주의 - 10 / 3 * 3은 9가 아닌 10