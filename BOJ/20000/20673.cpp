// Covid-19
// https://www.acmicpc.net/problem/20673

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p, q;
	cin >> p >> q;

	if (p <= 50 && q <= 10) {
		cout << "White\n";
	}
	else if (q > 30) {
		cout << "Red\n";
	}
	else {
		cout << "Yellow\n";
	}
}

// 신규 확진자와 중증 환자 수가 주어질 때, 주어진 기준에 따라 경고단계 분류하기
// 신규 확진자가 50 이하고 중증 환자가 10 이하인 경우 White, 중증 환자가 30을 넘는 경우 Red, 그 외에는 Yellow

// 그렇게 분류합시다