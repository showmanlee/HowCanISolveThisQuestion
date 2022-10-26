// 카우버거
// https://www.acmicpc.net/problem/15720

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int b, c, d;
	cin >> b >> c >> d;
	vector<int> burger(b), side(c), beverage(d);
	int resa = 0, resb = 0;
	for (int i = 0; i < b; i++) {
		cin >> burger[i];
		resa += burger[i];
	}
	for (int i = 0; i < c; i++) {
		cin >> side[i];
		resa += side[i];
	}
	for (int i = 0; i < d; i++) {
		cin >> beverage[i];
		resa += beverage[i];
	}
	sort(burger.begin(), burger.end(), greater<int>());
	sort(side.begin(), side.end(), greater<int>());
	sort(beverage.begin(), beverage.end(), greater<int>());
	int p = min(b, min(c, d));
	for (int i = 0; i < p; i++) {
		resb += burger[i] * 0.9;
		resb += side[i] * 0.9;
		resb += beverage[i] * 0.9;
	}
	for (int i = p; i < b; i++) {
		resb += burger[i];
	}
	for (int i = p; i < c; i++) {
		resb += side[i];
	}
	for (int i = p; i < d; i++) {
		resb += beverage[i];
	}
	cout << resa << '\n' << resb << '\n';
}

// 주어진 버거, 사이드, 음료들을 시킬 때 각각 한 종류씩 묶어서 사면 10% 할인을 받을 수 있을 때, 할인 없이 사는 값과 가장 저렴한 가격으로 사는 경우 구하기

// 퍼센트 할인이므로 무조건 비싼 메뉴를 세트로 만드는 게 이득
// 이를 위해 각 카테고리 배열을 내림차순으로 정렬해서, 종류가 가장 적은 수만큼의 메뉴를 앞에서부터 할인시킨다
// 남은 메뉴들은 정가로 더하면 최대 할인가가 나오지