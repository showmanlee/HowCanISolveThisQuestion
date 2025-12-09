// 아 마이마이 하고 싶다
// https://www.acmicpc.net/problem/34692

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(m);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		int idx = 0, minn = 1987654321;
		for (int j = 0; j < m; j++) {
			if (minn > v[j]) {
				idx = j;
				minn = v[j];
			}
		}
		v[idx] += p;
	}
	bool res = false;
	for (int i = 0; i < m; i++) {
		if (v[i] <= k) {
			res = true;
			break;
		}
	}
	cout << (res ? "WAIT" : "GO") << '\n';
}

// 오락실 n대의 기계에 각자 예상 플레이타임이 다른 사람들이 m대에 나누어 서있고, 다른 오락실로 가는데 k가 걸릴 때, 다른 오락실로 가야 더 빨리 할 수 있는지 구하기