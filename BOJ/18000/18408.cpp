// 3 つの整数 (Three Integers)
// https://www.acmicpc.net/problem/18408

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int one = 0, two = 0;
	for (int i = 0; i < 3; i++) {
		int p;
		cin >> p;
		if (p == 1) {
			one++;
		} else {
			two++;
		}
	}
	cout << (one > two ? "1" : "2") << '\n';
}

// 1 또는 2가 적힌 3개의 정수가 주어졌을 때, 더 많은 수 출력하기

// 숫자 3개 입력받고 뭐가 더 많은지 세어보면 되지요