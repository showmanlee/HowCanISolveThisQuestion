// 바이너리 왕국
// https://www.acmicpc.net/problem/16567

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> board(n + 2);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
		if (board[i - 1] == 0 && board[i] == 1) {
			res++;
		}
	}
	for (int t = 0; t < m; t++) {
		int d;
		cin >> d;
		if (d == 0) {
			cout << res << '\n';
		} else {
			int p;
			cin >> p;
			if (board[p] == 0) {
				board[p] = 1;
				if (board[p - 1] == 0 && board[p + 1] == 0) {
					res++;
				} else if (board[p - 1] == 1 && board[p + 1] == 1) {
					res--;
				}
			}
		}
	}
}

// 길이 n의 1차원 보드에 1을 그려넣을 떄, 모든 1을 지우는데 드는 획 수 구하기