// Texture Wrapping
// https://www.acmicpc.net/problem/33558

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, u, v;
	cin >> n >> m >> u >> v;
	vector<vector<char>> board(u, vector<char>(v)), res(n, vector<char>(m));
	for (int i = 0; i < u; i++) {
		for (int j = 0; j < v; j++) {
			cin >> board[i][j];
		}
	}
	string s;
	cin >> s;
	if (s == "clamp-to-edge") {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = board[min(i, u - 1)][min(j, v - 1)];
			}
		}
	} else if (s == "repeat") {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = board[i % u][j % v];
			}
		}
	} else if (s == "mirrored-repeat") {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = (i % (u * 2) < u ? i % (u * 2) : (u * 2 - 1) - (i % (u * 2)));
				int y = (j % (v * 2) < v ? j % (v * 2) : (v * 2 - 1) - (j % (v * 2)));
				res[i][j] = board[x][y];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j];
		}
		cout << '\n';
	}
}

// u*v 크기의 텍스처를 n*m 보드에 주어진 방식으로 채우기