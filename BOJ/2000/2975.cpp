// Transactions
// https://www.acmicpc.net/problem/2975

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int a, b;
		char c;
		cin >> a >> c >> b;
		if (a == 0 && b == 0 && c == 'W') {
			break;
		}
		a += (c == 'D' ? b : -b);
		if (a < -200) {
			cout << "Not allowed\n";
		} else {
			cout << a << '\n';
		}
	}
}

// 최대 -200까지 빚을 질 수 있는 마이너스통장에 입금/출금할 때 거래 가능 여부 또는 잔액 출력하기

// 주어진 대로 잔고에서 금액을 더하고 뺴서 -200 미만이 나오면 Not Allowed, 아니면 새로운 잔액 출력하기