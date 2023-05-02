// Simple Sum
// https://www.acmicpc.net/problem/26531

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char a, b, c, _;
	cin >> a >> _ >> b >> _ >> c;
	a -= '0';
	b -= '0';
	c -= '0';
	cout << (a + b == c ? "YES" : "NO") << '\n';
}

// A + B = C 꼴의 수식이 참인지 판정하기

// A, B, C가 모두 한 자릿수임이 보장되므로 char로 받아서 계산하기