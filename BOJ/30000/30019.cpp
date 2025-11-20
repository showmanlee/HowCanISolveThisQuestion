// 강의실 예약 시스템
// https://www.acmicpc.net/problem/30019

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 0; i < m; i++) {
		int a, x, y;
		cin >> a >> x >> y;
		if (v[a] <= x) {
			cout << "YES\n";
			v[a] = y;
		} else {
			cout << "NO\n";
		}
	}
}

// 강의실과 예약 시간들이 주어질 때, 예약 성공/실패 여부 구하기