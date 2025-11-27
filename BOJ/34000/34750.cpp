// 추석은 언제나 좋아
// https://www.acmicpc.net/problem/34750

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = 0;
	if (n >= 1000000) {
		p = n / 100 * 20;
	} else if (n >= 500000) {
		p = n / 100 * 15;
	} else if (n >= 100000) {
		p = n / 100 * 10;
	} else {
		p = n / 100 * 5;
	}
	n -= p;
	cout << p << ' ' << n << '\n';
}

// 주어진 돈의 분배 결과 구하기