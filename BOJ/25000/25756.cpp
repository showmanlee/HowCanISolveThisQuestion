// 방어율 무시 계산하기
// https://www.acmicpc.net/problem/25756

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(6);

	int n;
	cin >> n;
	double res = 0;
	for (int i = 0; i < n; i++) {
		double p;
		cin >> p;
		p /= 100;
		res = 1 - (1 - res) * (1 - p);
		cout << (res * 100) << '\n';
	}
}

// 현재 방어율 무시 수치가 v고 방어율 무시 효과가 p인 물약을 먹으면 방어율 무시 수치가 1 - (1 - v) * (1 - p)가 될 때, 물약을 먹을 때마다 방어율 무시 수치가 어떻게 변하는지 출력하기

// 백분율임에만 주의하면서 숫자 받으면서 출력해준다