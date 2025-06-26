// 거리 두기 게임
// https://www.acmicpc.net/problem/30052

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, d;
	cin >> n >> m >> d;
	vector<vector<bool>> board(n + 1, vector<bool>(m));
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (abs(1 - i) + abs(1 - j) >= d) {
				board[i][j] = true;
			}
			if (abs(1 - i) + abs(m - j) >= d) {
				board[i][j] = true;
			}
			if (abs(n - i) + abs(1 - j) >= d) {
				board[i][j] = true;
			}
			if (abs(n - i) + abs(m - j) >= d) {
				board[i][j] = true;
			}
			if (!board[i][j]) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// n*m 보드에서 둘 사이의 택시 거리가 d 이상이 되게 하기 위해 말을 놓을 수 없는 칸을 둘 때, 최솟값 구하기