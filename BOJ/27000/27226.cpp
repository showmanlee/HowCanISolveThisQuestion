// Лестница из чисел
// https://www.acmicpc.net/problem/27226

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b, k;
	cin >> a >> b >> k;
	for (long long i = a; i <= b; i++) {
		long long p = (i * (i - 1) / 2) + 1;
		for (int j = 0; j < min(i, k); j++) {
			cout << p + j << ' ';
		}
		cout << '\n';
	}
}

// 숫자 피라미드에서 문제에 주어진 대로 일부만 출력하기