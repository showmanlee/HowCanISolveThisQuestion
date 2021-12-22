// Patyki
// https://www.acmicpc.net/problem/8723

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 2; i++) {
		if (a > b) {
			swap(a, b);
		}
		if (b > c) {
			swap(b, c);
		}
	}
	if (a * a + b * b == c * c) {
		cout << 1 << '\n';
	}
	else if (a == b && b == c) {
		cout << 2 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
}

// 주어진 막대기 3개로 정삼각형이나 직각삼각형을 만들 수 있는지 판정하기

// 막대기를 길이 순으로 정렬하고, 세 길이가 모두 같거나 피타고라스의 정리에 맞는지 확인하기