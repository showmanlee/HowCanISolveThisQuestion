// 전자레인지
// https://www.acmicpc.net/problem/14470

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int res = 0;
	if (a < 0)
		res += -a * c;
	if (a <= 0)
		res += d;
	res += (b - max(0, a)) * e;
	cout << res << '\n';
}

// a도의 고기를 b도로 익히기 위해 0도까지 올리는데 1도당 c초, 0도에서 해동시키는데 d초, b도까지 익히는데 1도당 e초가 걸릴 때, 익히는 총 시간은?

// a도에서 0도가 될 때까지는 c초씩, 0도가 되는 순간 d초, b도가 될 때까지 e초를 추가하기