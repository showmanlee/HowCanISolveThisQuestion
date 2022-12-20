// 지뢰찾기
// https://www.acmicpc.net/problem/4108

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<vector<char>> board(n, vector<char>(m));
		vector<vector<int>> res(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				if (board[i][j] == '*') {
					for (int t = 0; t < 8; t++) {
						int xx = i + dx[t];
						int yy = j + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
							continue;
						}
						res[xx][yy]++;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '*') {
					cout << '*';
				} else {
					cout << res[i][j];
				}
			}
			cout << '\n';
		}
	}
}

// n*m 보드의 지뢰 현황이 주어질 때, 빈 칸에 대해 8방향으로 지뢰가 몇 개 있는지 지뢰찾기 보드 출력하기

// 보드 입력을 받을 배열과 각 칸의 주변 지뢰 개수륽 셀 배열을 함께 만든다
// 이후 배열 입력을 받으며 해당 칸이 지뢰일 경우 그 주변 칸들에 대해 개수++
// 이후 지뢰 칸을 제외한 나머지 칸은 . 대신 개수를 출력해준다 