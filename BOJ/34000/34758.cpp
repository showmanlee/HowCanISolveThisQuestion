// KUPC에 어서 오세요
// https://www.acmicpc.net/problem/34758

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y, n;
	cin >> x >> y >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int res = (x == a || y == b ? 0 : 1);
		cout << res << '\n';
	}
}

// 2차원 보드에서 축에 평행한 방향으로 (x, y)에 도달할 때, 방향 전환이 필요한지 여부 출력하기