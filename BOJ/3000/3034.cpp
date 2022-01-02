// 앵그리 창영
// https://www.acmicpc.net/problem/3034

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	double w, h;
	cin >> n >> w >> h;
	double target = sqrt(w * w + h * h);
	for (int i = 0; i < n; i++) {
		double p;
		cin >> p;
		cout << (target >= p ? "DA" : "NE") << '\n';
	}
}

// n*m 상자 속에 성냥을 바닥에 모두 닿게 넣을 수 있는지 판정하기

// 피타고라스의 정리 이용하기 - 성냥의 길이가 sqrt(w * w + h * h) 이하면 들어갑니다