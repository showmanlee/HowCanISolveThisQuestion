// 3000번 버스
// https://www.acmicpc.net/problem/9546

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int p;
		cin >> p;
		int res = 1;
		for (int i = 1; i < p; i++) {
			res = res * 2 + 1;
		}
		cout << res << '\n';
	}
}

// 매 정류장마다 승객이 절반 + 0.5명씩 내릴 때, p번째 정류장 전에 타고 있는 사람 수는?

// 절반 + 0.5명이 빠질 때 정수가 되어야 하므로 매 항의 값은 홀수
// 이미 1과 3의 값이 나와 있기에 이를 이용해 규칙을 찾아볼 수 있음