// 쿠폰
// https://www.acmicpc.net/problem/10179

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < n; i++) {
		double p;
		cin >> p;
		p *= 0.8;
		cout << '$' << p << '\n';
	}
}

// 주어진 금액의 20% 할인가 출력하기

// precision 지정하고, 주어진 double 값에 0.8을 곱한 값 $ 기호와 함께 출력하기