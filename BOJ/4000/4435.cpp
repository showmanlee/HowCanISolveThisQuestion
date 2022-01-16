// 중간계 전쟁
// https://www.acmicpc.net/problem/4435

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int a, b, c, d, e, f, g, h, i, j, k, l, m;
		cin >> a >> b >> c >> d >> e >> f;
		cin >> g >> h >> i >> j >> k >> l >> m;
		int r1 = a + b * 2 + c * 3 + d * 3 + e * 4 + f * 10;
		int r2 = g + h * 2 + i * 2 + j * 2 + k * 3 + l * 5 + m * 10;
		cout << "Battle " << t << ": ";
		if (r1 > r2) {
			cout << "Good triumphs over Evil\n";
		}
		else if (r1 < r2) {
			cout << "Evil eradicates all trace of Good\n";
		}
		else {
			cout << "No victor on this battle field\n";
		}
	}
}

// 각 편의 병력 수에 종족 가중치를 곱해서 합친 점수로 전쟁 승패를 가를 때, 최종 결과 출력하기

// 문제에 나온 가중치를 잘 보고 계산에 반영합시다