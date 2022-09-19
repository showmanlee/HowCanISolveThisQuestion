// 에어팟
// https://www.acmicpc.net/problem/25495

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int combo = 2;
	int res = 0;
	int prev = -1;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (prev == p) {
			combo *= 2;
		} else {
			combo = 2;
		}
		res += combo;
		prev = p;
		if (res >= 100) {
			res = 0;
			prev = -1;
			combo = 2;
		}
	}
	cout << res << '\n';
}

// 다음 방식으로 에어팟을 휴대폰에 연결할 때, 최종 배터리 소모량 구하기
// - 휴대폰에 연결할 때마다 2%씩 소모되며, 같은 휴대폰에 연결할 경우 직전 소모량의 2배씩 소모된다(2-4-8-16...)
// - 이 과정에서 에어팟 배터리가 고갈될 경우(100%), 새로운 에어팟으로 교체하며 배터리 소모량은 0%가 되고 소모량 증가량은 초기화된다

// 저 조건을 감안하여 조건문을 짜줍니다 - 이전 폰 번호, 현재 소모량 콤보를 이용하면서
// 만약 배터리 소모량이 100%가 될 경우 결과를 0으로 맞추고, 콤보를 2로 초기화하며, 이전 인덱스로 -1로 둔다 