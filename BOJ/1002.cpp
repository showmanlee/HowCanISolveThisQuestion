// 터렛
// https://www.acmicpc.net/problem/1002

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		long long dist = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
		long long plus = (r1 + r2) * (r1 + r2);
		long long minus = abs(r1 - r2) * abs(r1 - r2);
		if (dist < plus && dist > minus)
			cout << 2;
		else if (dist == plus)
			cout << 1;
		else if (dist == minus && dist != 0)
			cout << 1;
		else if (dist > plus || dist < minus)
			cout << 0;
		else if (dist == 0 && r1 == r2)
			cout << -1;
		else
			cout << 0;
		cout << '\n';
	}
}

// 두 터렛의 위치와 각 터렛과 마린의 거리가 주어졌을 때, 마린이 있을 수 있는 위치 수는?

// 터렛과 마린의 거리는 곧 반경 - '위치'를 중심으로 하는 반지름 '거리'의 원의 위치로 판정
// 이때 원 안에 다른 원이 있을 수 있음에 주의
// 따라서 나올 수 있는 경우의 수는 4가지 - 2, 1, 0, -1(inf)
// 원이 겹치는 경우 - 2
//  dist < r1 + r2 && dist > r1 - r2
// 원이 접하는 경우 - 1
//  dist == r1 + r2 || dist == r1 - r2 && dist != 0
// 원이 만나지 않는 경우 - 0
//  dist > r1 + r2 || dist < r1 - r2
// 원이 겹치는 경우 - -1
//  dist == 0 && r1 == r2
// 루트 씌워서 계산하면 정확한 결과가 나오지 않을 수 있기에 제곱 상태로 계산