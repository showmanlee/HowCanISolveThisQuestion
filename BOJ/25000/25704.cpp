// 출석 이벤트
// https://www.acmicpc.net/problem/25704

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, p;
	cin >> n >> p;
	int res = p;
	if (n >= 5) {
		res = min(res, p - 500);
	}
	if (n >= 10) {
		res = min(res, (int)(p * 0.9));
	}
	if (n >= 15) {
		res = min(res, p - 2000);
	}
	if (n >= 20) {
		res = min(res, (int)(p * 0.75));
	}
	if (res < 0) {
		res = 0;
	}
	cout << res << '\n';
}

// 모든 도장의 수에 따라 5개는 500원 할인, 10개는 10% 할인, 15개는 2000원 할인, 20개는 25% 할인 쿠폰을 받을 수 있을 때, 쿠폰을 최대 1장만 써서 얻을 수 있는 최소 가격 출력하기

// 원가를 도장 수에 따라 가능한 할인 경우의 수와 비교해서 저렴한 값을 찾고, 할인양이 음수인 경우 0으로 바꾸기