// Scores of Final Examination
// https://www.acmicpc.net/problem/17577

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<vector<int>> board(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		int res = 0;
		for (int j = 0; j < n; j++) {
			int p = 0;
			for (int i = 0; i < m; i++) {
				p += board[i][j];
			}
			res = max(res, p);
		}
		cout << res << '\n';
	}
}

// 점수 테이블에서 가장 높은 합산 점수 구하기