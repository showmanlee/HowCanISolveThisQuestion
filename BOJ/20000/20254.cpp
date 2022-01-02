// Site Score
// https://www.acmicpc.net/problem/20254

#include <iostream>
using namespace std;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int res = (56 * a) + (24 * b) + (14 * c) + (6 * d);
	cout << res << '\n';
}

// 56a + 24b + 14c + 6d 구하기
// '계산기' 활용