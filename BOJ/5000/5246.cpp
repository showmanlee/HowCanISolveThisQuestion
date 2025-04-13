// Checkerboard Rows
// https://www.acmicpc.net/problem/5246

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<int> v(9);
		int res = 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			v[y]++;
			res = max(res, v[y]);
		}
		cout << res << '\n';
	}
}

// 8*8 보드에서 n개의 돌이 놓인 위치가 주어질 때, 가장 많은 돌이 있는 열의 돌 개수 구하기