// 사칙연산
// https://www.acmicpc.net/problem/13420

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b, c;
		char op, eq;
		cin >> a >> op >> b >> eq >> c;
		long long res = 0;
		if (op == '+')
			res = a + b;
		else if (op == '-')
			res = a - b;
		else if (op == '*')
			res = a * b;
		else if (op == '/')
			res = a / b;
		cout << (res == c ? "correct" : "wrong answer") << '\n';
	}
}

// 사칙연산 수식이 주어질 때, 그 결과가 맞는지 확인하기

// 실제로 넣어보면 되지요