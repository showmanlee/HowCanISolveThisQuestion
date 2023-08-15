// 통학의 신
// https://www.acmicpc.net/problem/17945

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int b, c;
	cin >> b >> c;
	int x = (-b - sqrt(b * b - c));
	int y = (-b + sqrt(b * b - c));
	cout << x;
	if (x != y) {
		cout << ' ' << y;
	}
	cout << '\n';
}

// x^2 + 2bx + c 꼴의 이차방정식의 두 근 구하기

// 근의 공식이란 걸 써줍시다 - 그것도 짝수의 근의 공식으로다가