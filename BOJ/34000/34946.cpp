// 셔틀 탈래 말래 탈래 말래 애매하긴 해
// https://www.acmicpc.net/problem/34946

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool x = (a + b) <= d;
	bool y = c <= d;
	cout << (x ? (y ? "~.~" : "Shuttle") : (y ? "Walk" : "T.T")) << '\n';
}

// a+b, c 중 d보다 작거나 같은 거 구하기