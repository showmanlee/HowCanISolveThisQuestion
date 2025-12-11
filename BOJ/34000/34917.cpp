// M
// https://www.acmicpc.net/problem/34917

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
		vector<vector<char>> v(n, vector<char>(n, '.'));
		for (int i = 0; i < n; i++) {
			v[i][0] = v[i][n - 1] = '#';
			v[(i <= n / 2 ? i : n - i - 1)][i] = '#';
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << v[i][j];
			}
			cout << '\n';
		}
	}
}

// 주어진 대로 M 찍기