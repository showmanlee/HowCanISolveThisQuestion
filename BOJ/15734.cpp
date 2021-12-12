// 명장 남정훈
// https://www.acmicpc.net/problem/15734

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, r, a;
	cin >> l >> r >> a;
	if (l < r) {
		int p = (a < r - l ? a : r - l);
		a -= p;
		l += p;
	}
	else {
		int p = (a < l - r ? a : l - r);
		a -= p;
		r += p;
	}
	if (a >= 2) {
		l += a / 2;
		r += a / 2;
		a %= 2;
	}
	cout << (min(l, r) * 2) << '\n';
}

// 왼발잡이와 오른발잡이의 수를 동일하게 하여 로스터를 짜는 상황에서 양발잡이는 왼발잡이나 오른발잡이의 부족한 인원 수로 채울 수 있을 때, 확정된 로스터 인원 수 출력하기

// 부족한 쪽에 양발잡이 인원을 채울 수 있을 만큼 넣고, 양발잡이 인원이 남았다면 양쪽에 동일하게 남은 인원을 채워준다
// 결과는 양쪽 인원 수 중 적은 인원의 *2 - 양쪽 인원수는 같아야하므로