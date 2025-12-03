// Bus Assignment
// https://www.acmicpc.net/problem/32800

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cur -= a;
		cur += b;
		res = max(res, cur);
	}
	cout << res << '\n';
}

// 버스 승하차 현황이 주어질 때 최대 인원수 구하기