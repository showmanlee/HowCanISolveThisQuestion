// 피로도
// https://www.acmicpc.net/problem/22864

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, m;
	cin >> a >> b >> c >> m;
	int res = 0;
	for (int i = 0; i <= 24; i++) {
		int p = max(a * i - c * (24 - i), 0);
		if (p <= m)
			res = b * i;
	}
	if (a > m)
		res = 0;
	cout << res << '\n';
}

// 24시간 중 1시간 단위로 b만큼의 일을 처리하고 a의 피로도를 얻거나, 일을 하지 않고 c의 피로도를 덜 수 있을 때, 누적 피로도가 m을 초과하지 않고 처리할 수 있는 일의 최대는?

// 0부터 24까지 i를 순회시키면서 a * i - c * (24 - i)를 계산한 후 이 값이 m 이하일 때 b * i를 결과값으로 갱신한다
// 다만 여기서 피로도가 최대치를 벗어나는 순간 했던 일도 모두 사라지게 됨 - a > m일 경우, 1시간만 일해도 피로도가 초과하여 일 자체가 불가능
// 따라서 a > m일 경우, 무조건 결과값이 0이 되어야 함