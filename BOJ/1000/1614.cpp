// 영식이의 손가락
// https://www.acmicpc.net/problem/1614

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	long long p, n;
	cin >> p >> n;
	long long res = 0;
	if (p == 1) {
		res = 8 * n;
	} else if (p == 2) {
		if (n % 2 == 0) {
			res = 1 + 8 * (n / 2);
		} else {
			res = 7 + 8 * (n / 2);
		}
	} else if (p == 3) {
		if (n % 2 == 0) {
			res = 2 + 8 * (n / 2);
		} else {
			res = 6 + 8 * (n / 2);
		}
	} else if (p == 4) {
		if (n % 2 == 0) {
			res = 3 + 8 * (n / 2);
		} else {
			res = 5 + 8 * (n / 2);
		}
	} else if (p == 5) {
		res = 4 + 8 * n;
	}
	cout << res << '\n';
}

// 12345432 순으로 손가락을 굴려가며 수를 셀 때, p번 손가락을 n번만 쓸 수 있는 상황에서 최고로 셀 수 있는 수 출력하기

// 1/5번 손가락은 한 번만 카운트 - 나머지는 두 번씩 카운트
// 규칙이 보일 겁니다...