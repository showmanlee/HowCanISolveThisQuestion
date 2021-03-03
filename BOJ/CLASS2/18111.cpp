// 마인크래프트
// https://www.acmicpc.net/submit/18111

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int res = 1234567890, height = 0;
	for (int g = 0; g <= 256; g++) {
		int up = 0, down = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] > g)
					down += board[i][j] - g;
				else
					up += g - board[i][j];
			}
		}
		if (up <= down + b) {
			int r = up + down * 2;
			if (r < res)
				res = r;
			if (r == res)
				height = g;
		}
	}
	cout << res << ' ' << height << '\n';
}

// 땅을 파서 인벤토리에 넣는데 2초, 덮는데 1초가 걸릴 때, 인벤토리를 고려해 땅을 고를 때 최소로 걸리는 시간과 그 높이는?
// 0~256까지 모두 대응해보는 브루트포스 - 레인지를 안 줄어도 괜찮음 괜찮음