// Club Pizza
// https://www.acmicpc.net/problem/34291

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;
	vector<vector<int>> v(24, vector<int>());
	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		v[t].push_back(p);
	}
	vector<int> resv;
	for (int i = 0; i < 24; i++) {
		if (v[i].empty()) {
			continue;
		}
		sort(v[i].begin(), v[i].end());
		resv.push_back(v[i][0]);
	}
	sort(resv.begin(), resv.end());
	int res = 0;
	for (int i : resv) {
		c -= i;
		if (c < 0) {
			break;
		}
		res++;
	}
	cout << res << '\n';
}

// 매 시간 하나의 집에 들어가 정해진 양의 피자를 먹을 수 있을 때, 최대 c개의 피자를 먹는데 방문할 수 있는 집의 최대 개수 구하기