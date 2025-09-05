// Snowflakes
// https://www.acmicpc.net/problem/26498

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
		vector<vector<char>> v(n, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		bool beautiful = true, graceful = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (v[i][j] != v[i][n - j - 1]) {
					graceful = false;
				}
				if (v[j][i] != v[n - j - 1][i]) {
					beautiful = false;
				}
			}
		}
		cout << (beautiful ? (graceful ? "Magnificent" : "Beautiful") : (graceful ? "Graceful" : "Useless")) << '\n';
	}
}

// n*n 보드에서 모든 원소가 수직/수평 대칭인지 확인하기