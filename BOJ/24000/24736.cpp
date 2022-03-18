// Football Scoring
// https://www.acmicpc.net/problem/24736

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d, e, f, g, h, i, j;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
	cout << (a * 6 + b * 3 + c * 2 + d + e * 2) << ' ' << (f * 6 + g * 3 + h * 2 + i + j * 2) << '\n';
}

// 각 팀당 6/3/2/1/2점을 얻을 수 있는 행동을 했을 때, 각 팀의 최종 결과 출력하기

// 단순 덧셈