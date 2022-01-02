// 성냥개비
// https://www.acmicpc.net/problem/23842

#include <iostream>
#include <algorithm>
using namespace std;

int count(int p) {
	if (p == 1)
		return 2;
	if (p == 7)
		return 3;
	if (p == 4)
		return 4;
	if (p == 2 || p == 3 || p == 5)
		return 5;
	if (p == 6 || p == 9 || p == 0)
		return 6;
	if (p == 8)
		return 7;
	return 98765432;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	bool res = false;
	n -= 4;
	for (int i = 0; i < 1000000; i++) {
		int a = i / 100000;
		int b = i / 10000 % 10;
		int c = i / 1000 % 10;
		int d = i / 100 % 10;
		int e = i / 10 % 10;
		int f = i % 10;
		if ((a * 10 + b) + (c * 10 + d) == (e * 10 + f)) {
			if (count(a) + count(b) + count(c) + count(d) + count(e) + count(f) == n) {
				res = true;
				cout << a << b << '+' << c << d << '=' << e << f << '\n';
				break;
			}
		}
	}
	if (!res) {
		cout << "impossible" << '\n';
	}
}

// 성냥개비 n개로 __ + __ = __ 꼴의 수식을 만들 때, 가능한 수식은?(부호는 각각 2개씩 필요)

// 6자리를 채워야 하기에 경우의 수는 100만개 - 브포로 가능
// 6자리를 딴 뒤, 그 여섯 자리로 수식이 성립하는지 확인
// 성립한다면 숫자를 만드는데 필요한 성냥개비 수가 n - 4개인지 확인
// 둘 다 맞다면 출력
// 최종적으로 그런 게 없다면 impossible 출력하기