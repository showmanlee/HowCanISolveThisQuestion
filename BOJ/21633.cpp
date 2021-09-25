// Bank Transfer
// https://www.acmicpc.net/problem/21633

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double p;
	cin >> p;
	double res = 25 + (p * 0.01);
	if (res <= 100)
		res = 100;
	else if (res >= 2000)
		res = 2000;
	cout << fixed;
	cout.precision(2);
	cout << res << '\n';
}

// 기본적으로 25 + 1%인 수수료가 최저 100, 최대 2000을 넘지 못할 때, 주어진 금액을 송금하기 위해 필요한 수수료 구하기

// 조건만 잘 넣고, 소수 뒤 두 자리수 출력 지키면서 출력만 해주면 됩니다..!