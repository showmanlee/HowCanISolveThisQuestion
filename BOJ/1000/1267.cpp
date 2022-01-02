// 핸드폰 요금
// https://www.acmicpc.net/problem/1267

#include <iostream>
using namespace std;

int main(void) {
	int y = 0, m = 0, n, p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		y += (p / 30 + 1) * 10;
		m += (p / 60 + 1) * 15;
	}
	cout << (y <= m ? (y == m ? "Y M " : "Y ") : "M ") << (y <= m ? y : m) << '\n';
}

// 30초마다 10원씩 나오는 요금제와 60초마다 15원씩 나오는 요금제가 있을 때 어떤 요금제를 써야 더 저렴한가?
// 들어올 때마다 나누기 + 1 연산