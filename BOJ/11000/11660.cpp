// 구간 합 구하기 5
// https://www.acmicpc.net/problem/11660

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int p;
			cin >> p;
			board[i][j] = board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1] + p;
		}
	}
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int res = board[x2][y2] - board[x1 - 1][y2] - board[x2][y1 - 1] + board[x1 - 1][y1 - 1];
		cout << res << '\n';
	}
}

// 2차원 보드에서 (x1, y1)부터 (x2, y2)까지의 누적합 구하기

// 2차원 보드의 (1,1)부터 해당 칸까지의 누적합을 미리 구해두고 쿼리에 맞춰 계산해서 출력한다 - 교집합 및 차집합 생각해서