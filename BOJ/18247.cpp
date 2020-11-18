// 겨울왕국 티켓 예매
// https://www.acmicpc.net/problem/18247

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 12 || b < 4) {
			cout << -1 << '\n';
			continue;
		}
		cout << b * 11 + 4 << '\n';
	}
}

// L(12)열 4번째 좌석이 있는가? 있다면 앞에서부터 몇 번째 자리인가?