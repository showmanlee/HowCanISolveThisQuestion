// 컵라면의 높이
// https://www.acmicpc.net/problem/16479

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	float k, d1, d2;
	cin >> k >> d1 >> d2;
	float a = ((d1 - d2) / 2) * ((d1 - d2) / 2);
	float c = k * k;
	float res = c - a;
	cout << res << '\n';
}

// 등변사다리꼴의 빗면의 길이와 윗변/아랫변의 길이가 주어졌을 때, 높이^2 구하기

// 빗면의 길이가 주어진 상태이므로 평행변 길이 차 / 2를 밑변으로 하여 피타고라스를 써먹을 수 있다 - 그래서 높이 제곱을 구하라는 것
// 그런 식으로 구해주면 됩니다 - b^2 = c^2 - a^2