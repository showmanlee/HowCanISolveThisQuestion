// 롤 케이크
// https://www.acmicpc.net/problem/3985

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, n;
	cin >> l >> n;
	vector<int> cake(l + 1);
	int maxpc = 0, maxpn = 0;
	int maxac = 0, maxan = 0;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (b - a > maxpc) {
			maxpc = b - a;
			maxpn = i;
		}
		int cnt = 0;
		for (int j = a; j <= b; j++) {
			if (cake[j] == 0) {
				cake[j] = i;
				cnt++;
			}
		}
		if (cnt > maxac) {
			maxac = cnt;
			maxan = i;
		}
	}
	cout << maxpn << '\n' << maxan << '\n';
}

// l개의 연속된 조각 중 n명이 각자 원하는 조각 범위를 제시하고, 순서대로 (남은) 조각을 가져갈 때, 가장 많은 조각을 원한 사람과 실제로 가져간 사람은?

// 원한 사람의 경우 말한 범위가 가장 넒은 사람(중 번호가 가장 작은 사람)
// 가져간 사람의 경우 말한 범위에 실제로 숫자를 써보면서 적힌 수가 가장 많은 사람(중 번호가 가장 작은 사람)