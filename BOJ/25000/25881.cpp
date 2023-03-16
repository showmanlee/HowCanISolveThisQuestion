// Electric Bill
// https://www.acmicpc.net/problem/25881

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, tt;
	cin >> n >> m >> tt;
	for (int t = 0; t < tt; t++) {
		int p;
		cin >> p;
		int pp = p - 1000;
		int res = (p >= 1000 ? 1000 : p) * n + (p >= 1000 ? pp : 0) * m;
		cout << p << ' ' << res << '\n';
	}
}

// 초기 1000 kWh 사용분의 kWh당 요금과 초과분의 요금이 주어질 때, 주어진 사용량에 대한 요금 구하기

// 적절히 식을 세워서 구해봅시다