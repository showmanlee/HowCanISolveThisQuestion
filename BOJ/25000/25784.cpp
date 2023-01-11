// Easy-to-Solve Expressions
// https://www.acmicpc.net/problem/25784

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	if (a + b == c || a + c == b || b + c == a) {
		cout << 1 << '\n';
	} else if (a * b == c || a * c == b || b * c == a) {
		cout << 2 << '\n';
	} else {
		cout << 3 << '\n';
	}
}
 
// 세 자연수가 주어졌을 때, 어떤 수를 다른 두 수를 더해서 만들 수 있는 경우 1, 곱해서 만들 수 있는 경우 2, 둘 다 아니면 3 출력하기

// 직접 대보면서 알아봅니다