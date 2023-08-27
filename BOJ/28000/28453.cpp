// Previous Level
// https://www.acmicpc.net/problem/28453

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == 300) {
			cout << 1;
		} else if (p < 300 && p >= 275) {
			cout << 2;
		} else if (p < 275 && p >= 250) {
			cout << 3;
		} else {
			cout << 4;
		}
		cout << ' ';
	}
}

// 주어진 자연수를 300, 275~299, 250~274, ~249 범위로 출력하기

// ...