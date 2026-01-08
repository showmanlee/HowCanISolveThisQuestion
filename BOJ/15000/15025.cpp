// Judging Moose
// https://www.acmicpc.net/problem/15025

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	if (a == 0 && b == 0) {
		cout << "Not a moose";
	} else if (a == b) {
		cout << "Even " << (a * 2);
	} else {
		cout << "Odd " << (max(a, b) * 2);
	}
	cout << '\n';
}

// 두 수 중 가장 큰 수 * 2를 규칙에 맞게 출력하기