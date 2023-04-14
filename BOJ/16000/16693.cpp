// Pizza Deal
// https://www.acmicpc.net/problem/16693

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double a, p1, r, p2;
	cin >> a >> p1 >> r >> p2;
	double aa = a / p1;
	double rr = r * r * M_PI / p2;
	if (aa > rr) {
		cout << "Slice of pizza\n";
	} else {
		cout << "Whole pizza\n";
	}
}

// 조각 피자의 넓이/가격과 원형 피자의 반지름/가격이 주어질 때, 같은 가격으로 더 많이 살 수 있는 경우 구하기

// 달러당 가격 구하기 - 조각 피자는 넓이로, 원형 피자는 반지름으로 넓이를 구한 후 가격으로 나눈다