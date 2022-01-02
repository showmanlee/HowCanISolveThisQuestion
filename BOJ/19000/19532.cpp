// 수학은 비대면강의입니다
// https://www.acmicpc.net/problem/19532

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int x = 1000, y = 1000;
	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if (a * i + b * j == c && d * i + e * j == f) {
				x = i;
				y = j;
				break;
			}
		}
		if (x != 1000)
			break;
	}
	cout << x << ' ' << y << '\n';
}

// 연립방정식 ax + by = c, dx + ey = f에서 abcdef가 주어졌을 때, 연립방정식을 만족하는 xy 구하기
// 해가 유일하고, 범위가 -999~999 보장하므로 브루트포스로 접근할 수 있음
// 그러니까, x와 y에 -999~999를 모두 대입하면서 결과를 얻을 수 있다는 것