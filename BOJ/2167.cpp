// 2차원 배열의 합
// https://www.acmicpc.net/problem/2167

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int k;
	cin >> k;
	while (k--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int res = 0;
		for (int i = a - 1; i < x; i++)
			for (int j = b - 1; j < y; j++)
				res += board[i][j];
		cout << res << '\n';
	}
}

// 2차원 배열의 일정 범위의 합을 구하고 싶다
// 구하면 되지 뭐가 문제야