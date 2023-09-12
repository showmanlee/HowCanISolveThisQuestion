// 브실이와 친구가 되고 싶어 🤸‍♀️
// https://www.acmicpc.net/problem/29736

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int a, b, k, x;
	cin >> a >> b >> k >> x;
	int ta = max(0, k - x);
	int tb = k + x;
	ta = max(ta, a);
	tb = min(tb, b);
	int res = tb - ta + 1;
	if (res <= 0) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << res << '\n';
	}
}

// 푼 문제 수가 a~b인 사람들이 있을 때, k - x ~ k + x 문제를 푼 사람의 수 구하기

// 두 범위에서 서로 겹치는 부분 찾기 - 없으면 IMPOSSIBLE
// 두 범위의 최소/최댓값 중 최대/최솟값을 찾고, 그 둘의 차가 음수가 나오면 IMPOSSIBLE