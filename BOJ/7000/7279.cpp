// Autobusas
// https://www.acmicpc.net/problem/7279

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int res = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cnt += a - b;
		res = max(res, cnt - k);
	}
	cout << res << '\n';
}

// 버스 좌석 수와 타고 내린 승객 수가 주어질 때, 서서 간 최대 인원 구하기