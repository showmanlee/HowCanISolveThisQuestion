// 세 수
// https://www.acmicpc.net/problem/2985

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	if (a + b == c)
		cout << a << '+' << b << '=' << c << '\n';
	else if (a - b == c)
		cout << a << '-' << b << '=' << c << '\n';
	else if (a * b == c)
		cout << a << '*' << b << '=' << c << '\n';
	else if (a / b == c)
		cout << a << '/' << b << '=' << c << '\n';
	else if (a == b + c)
		cout << a << '=' << b << '+' << c << '\n';
	else if (a == b - c)
		cout << a << '=' << b << '-' << c << '\n';
	else if (a == b * c)
		cout << a << '=' << b << '*' << c << '\n';
	else if (a == b / c)
		cout << a << '=' << b << '/' << c << '\n';
}

// 세 자연수 사이에 등호와 사칙연산 기호를 넣어서 만들 수 있는 등식 출력하기

// 등호가 반드시 들어가야 하므로 앞과 뒤에 등호를 넣고, 나머지 자리에 각 기호를 넣었을 때 맞는 식이 나오면 그 식 출력하기
// else if로 이어서 맞는 식이 여러 개 나오지 않도록