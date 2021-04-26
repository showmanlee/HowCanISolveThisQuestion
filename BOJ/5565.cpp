// 영수증
// https://www.acmicpc.net/problem/5565

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = 0;
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		p += a;
	}
	cout << (n - p) << '\n';
}

// 책 10권의 총액과 9권의 개별 가격이 주어질 때, 나머지 1권의 가격은?
// 총액 - 개별 가격의 합