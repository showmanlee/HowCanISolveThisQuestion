// Chess Puzzle
// https://www.acmicpc.net/problem/5239

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
		vector<bool> x(9), y(9);
		int n;
		cin >> n;
		bool res = true;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (x[a] || y[b]) {
				res = false;
			}
			x[a] = true;
			y[b] = true;
		}
		cout << (res ? "SAFE" : "NOT SAFE") << '\n';
	}
}

// 사이즈가 n인 랭킹 보드에서 k점이 들어갈 등수 구하기