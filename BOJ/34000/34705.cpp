// 효구장
// https://www.acmicpc.net/problem/34705

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int x, y;
		cin >> x >> y;
		vector<int> v(5);
		for (int i = 0; i < 5; i++) {
			cin >> v[i];
		}
		bool res = false;
		for (int i = 0; i < 32; i++) {
			int p = 0;
			for (int j = 0; j < 5; j++) {
				if ((int)(i / pow(2, j)) % 2 == 0) {
					p += v[j];
				}
			}
			if (x <= p && p <= y) {
				res = true;
				break;
			}
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 5개 중 몇 개를 고른 합이 x 이상 y 이하 범위에 들어갈 수 있는지 확인하기