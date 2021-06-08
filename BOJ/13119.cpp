// Mountains Beyond Mountains
// https://www.acmicpc.net/problem/13119

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<char>> board(n + 1, vector<char>(m + 1, '.'));
	for (int i = 1; i <= m; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < p; j++)
			board[n - j][i] = '#';
	}
	for (int i = 1; i <= m; i++) {
		if (board[n - x + 1][i] == '.')
			board[n - x + 1][i] = '-';
		else
			board[n - x + 1][i] = '*';
		if (i % 3 == 0) {
			int t = n - x + 2;
			while (t <= n && board[t][i] == '.') {
				board[t][i] = '|';
				t++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << board[i][j];
		cout << '\n';
	}
}

// 각 열의 높이와 다리(터널)의 높이가 주어질 때, 다리(터널)을 놓은 결과 출력하기

// 우선 초기 보드에는 .을 기본으로 찍어두고, 높이를 받으면 높이만큼 #을 보드에 찍는다
// 이후 다리 높이에서 각 열을 순회하며 .칸에는 -, #칸에는 *를 찍는다
// 만약 해당 열의 번호가 i % 3 == 0을 만족한다면 다리를 놓은 칸의 바로 아랫칸부터 #를 만날 때까지 |를 찍는다
// 모두 문제에 나오는 내용 - 따라서 시키는 대로만 하면 됨