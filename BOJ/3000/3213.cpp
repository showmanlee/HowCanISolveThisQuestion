// 피자
// https://www.acmicpc.net/problem/3213

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int _14 = 0, _12 = 0, _34 = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "1/4") {
			_14++;
		} else if (s == "1/2") {
			_12++;
		} else if (s == "3/4") {
			_34++;
		}
	}
	int res = 0;

	res += _12 / 2;
	_12 %= 2;

	int m1 = min(_14, _34);
	res += m1;
	_14 -= m1;
	_34 -= m1;

	int m2 = min(_14 / 2, _12);
	res += m2;
	_14 -= m2 * 2;
	_12 -= m2;

	int m3 = min(_14, _12);
	res += m3;
	_14 -= m3;
	_12 -= m3;

	res += _14 / 4;
	_14 %= 4;
	if (_14 > 0) {
		res++;
	}
	res += _12 + _34;

	cout << res << '\n';
}

// 피자를 1/4, 1/2, 3/4판 먹을 수 있는 사람들이 있을 때, 모두가 원하는 양을 먹을 수 있도록 시킬 수 있는 피자의 최수 개수는?

// 1/2+1/2, 1/4+3/4, 1/4+1/4+1/2, 1/4+1/4+1/4+1/4로 한 판을 만들 수 있고, 그 외의 경우는 한 판으로 처리 불가
// 3/4판까지 생각하면 1/2+1/4도 있음
// 이 케이스들의 우선순위를 생각하면서 피자를 만들어주면 됨...