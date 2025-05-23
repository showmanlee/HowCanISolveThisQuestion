// 캠핑장 부지 평탄화
// https://www.acmicpc.net/problem/33900

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r, c;
	cin >> n >> m >> r >> c;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	vector<vector<int>> key(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> key[i][j];
		}
	}
	int res = 0;
	for (int x = 0; x <= n - r; x++) {
		for (int y = 0; y <= m - c; y++) {
			int k = board[x][y] - key[0][0];
			bool pass = true;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (board[x + i][y + j] - key[i][j] != k) {
						pass = false;
						break;
					}
				}
				if (!pass) {
					break;
				}
			}
			if (pass) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

//  n*m 보드의 모든 수를 r*c 보드의 수로 뺄 때 r*c 영역 내 수가 모두 동일해지는 경우의 수 찾기