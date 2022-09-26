// Triathlon
// https://www.acmicpc.net/problem/25600

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int a, d, g;
		cin >> a >> d >> g;
		int coef = 1;
		if (a == d + g) {
			coef = 2;
		}
		res = max(res, a * (d + g) * coef);
	}
	cout << res << '\n';
}

// 점수표에 적힌 세 점수 a, d, g를 a * (d + g) (a == (d + g)일 경우 *2)로 계산할 때, 가장 높은 점수 출력하기

// 직접 계산해보며 최대 점수를 구해보자ㄴ