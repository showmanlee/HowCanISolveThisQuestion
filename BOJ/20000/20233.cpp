// Bicycle
// https://www.acmicpc.net/problem/20233

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, x, b, y, t;
	cin >> a >> x >> b >> y >> t;
	cout << (t < 30 ? a : a + (x * (t - 30) * 21)) << ' ' << (t < 45 ? b : b + (y * (t - 45) * 21)) << '\n';
}

// 월 a원 정액 + 30분 초과 이용시 분당 x원 추가 / 월 b원 정액 + 45분 초과 이용시 분당 y원 추가의 자전거 이용료 플랜이 주어졌을 때, 21일 간 t분 동안 탈 때의 이용료들 구하기

// 직접 계산해봅니다...