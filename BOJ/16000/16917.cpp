// 양념 반 후라이드 반
// https://www.acmicpc.net/problem/16917

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long p = x, q = y, r = 0;
	long long res = 987654321987654321;
	while (p > 0 || q > 0) {
		res = min(res, p * a + q * b + r * c);
		p -= (p == 0 ? 0 : 1);
		q -= (q == 0 ? 0 : 1);
		r += 2;
	}
	res = min(res, r * c);
	cout << res << '\n';
}

// 후라이드, 양념, 반반 치킨을 구매할 수 있을 때 최소 후라이드 x마리, 양념 y마리를 살 수 있는 최소 가격은?
// 반반 2마리로 후라이드/양념 한마리를 만들 수 있는데, x/y는 최소를 지정한 것이므로 반반으로 만든 후라이드/양념이 x/y를 넘어도 됨
// while 안에서 후라이드/양념/반반 구매량을 갱신해준다 - 후라이드/양념을 하나씩 빼고(없으면 없는대로 두고), 그 자리에 반반을 두 마리 넣는다
// 후라이드 수와 양념 수가 모두 0이 될 때까지 후라이드/양념/반반 구매가를 이용해 결과를 최소로 갱신한 후, 마지막(후라이드/양념이 모두 0마리가 되고 모두 양념으로 대체되었을 때) 상황을 또 갱신한다