// Array Rotation
// https://www.acmicpc.net/problem/28456

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}
	int m;
	cin >> m;
	for (int t = 0; t < m; t++) {
		int c;
		cin >> c;
		if (c == 1) {
			int d;
			cin >> d;
			for (int i = n; i > 1; i--) {
				swap(v[d][i], v[d][i - 1]);
			}
		} else {
			vector<vector<int>> w(n + 1, vector<int>(n + 1));
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					w[j][n - i + 1] = v[i][j];
				}
			}
			v = w;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

// 주어진 n*n 배열을 변형하기s