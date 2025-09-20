// Oooh I See
// https://www.acmicpc.net/problem/32813

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int cnt = 0;
	int resx = 0, resy = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (board[i][j] == '0') {
				bool pass = true;
				for (int t = 0; t < 8; t++) {
					if (board[i + dx[t]][j + dy[t]] != 'O') {
						pass = false;
						break;
					}
				}
				if (pass) {
					cnt++;
					resx = i + 1;
					resy = j + 1;
				}
			}
		}
	}
	if (cnt == 1) {
		cout << resx << ' ' << resy;
	} else if (cnt == 0) {
		cout << "Oh no!";
	} else {
		cout << "Oh no! " << cnt << " locations";
	}
	cout << '\n';
}

// n*m 보드에서 O로 둘러싸인 0의 개수와 위치 구하기