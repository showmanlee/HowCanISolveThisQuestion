// 인경호 울타리 공사
// https://www.acmicpc.net/problem/33923

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	n--;
	m--;
	int res = 0;
	if (n != m) {
		res = min(n, m) * min(n, m);
	} else {
		res = (n - 1) * (n - 1) + 1;
	}
	cout << res << '\n';
}

// n*m 그리드에서 정사각형 울타리를 만들 때, 전체를 두르는 경우를 제외한 최대 면적 구하기