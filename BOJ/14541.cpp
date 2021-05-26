// Speed Limit
// https://www.acmicpc.net/problem/14541

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == -1)
			break;
		int res = 0, elap = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			res += a * (b - elap);
			elap = b;
		}
		cout << res << " miles\n";
	}
}

// 특정 시점까지 해당 속도로 움직였던 기록들이 주어질 때, 움직인 총 거리는?
// (속력 * (흐른 시간 - 그 전 시간))을 계속 더해준 뒤 출력하라는 것