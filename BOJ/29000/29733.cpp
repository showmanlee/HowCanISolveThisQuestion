// 3차원 지뢰찾기
// https://www.acmicpc.net/problem/29733

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int r, c, h;
	cin >> r >> c >> h;
	vector<vector<vector<char>>> board(h, vector<vector<char>>(r, vector<char>(c)));
	vector<vector<vector<int>>> res(h, vector<vector<int>>(r, vector<int>(c)));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == '*') {
					for (int dx = -1; dx <= 1; dx++) {
						for (int dy = -1; dy <= 1; dy++) {
							for (int dz = -1; dz <= 1; dz++) {
								if (dx == 0 && dy == 0 && dz == 0) {
									continue;
								}
								int xx = i + dx;
								int yy = j + dy;
								int zz = k + dz;
								if (xx < 0 || xx >= h || yy < 0 || yy >= r || zz < 0 || zz >= c) {
									continue;
								}
								res[xx][yy][zz]++;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (board[i][j][k] == '*') {
					cout << '*';
				} else {
					cout << (res[i][j][k] % 10);
				}
			}
			cout << '\n';
		}
	}
}

// 3차원 지뢰찾기 보드에서 지뢰의 위치가 주어졌을 때, 빈칸에 적히는 숫자%10 출력하기

// 지뢰가 나오면 그 주변 칸에 1을 더해준다