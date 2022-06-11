// 가희와 방어율 무시
// https://www.acmicpc.net/problem/25238

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	float a, b;
	cin >> a >> b;
	a -= b * 0.01 * a;
	cout << (a < 100) << '\n';
}

// 몬스터의 방어율 수치와 방어율 무시 퍼센트가 주어질 때, 방어율이 100 미만으로 떨어져 피해를 입힐 수 있는지 판정하기

// 직접 계산해보면 됩니다