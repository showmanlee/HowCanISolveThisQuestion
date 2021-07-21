// 전투 드로이드 가격
// https://www.acmicpc.net/problem/5361

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		double res = 350.34 * a + 230.90 * b + 190.55 * c + 125.30 * d + 180.90 * e;
		cout << '$' << res << '\n';
	}
}

// 가격이 정해진 각 부품의 필요 수량이 주어질 때, 총 비용 구하기

// 그저 연산하기 - precision은 2로 맞춰놓고