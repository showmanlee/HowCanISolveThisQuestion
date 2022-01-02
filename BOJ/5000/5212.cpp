// 지구 온난화
// https://www.acmicpc.net/problem/5212

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int minx = n - 1, maxx = 0;
	int miny = m - 1, maxy = 0;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	vector<vector<int>> count(n, vector<int>(m, 4));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'X') {
				count[i][j] = 0;
				for (int t = 0; t < 4; t++) {
					int xx = i + dx[t];
					int yy = j + dy[t];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m)
						count[i][j]++;
					else if (board[xx][yy] == '.')
						count[i][j]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (count[i][j] >= 3)
				board[i][j] = '.';
			else {
				minx = min(minx, i);
				maxx = max(maxx, i);
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
		}
	}
	for (int i = minx; i <= maxx; i++) {
		for (int j = miny; j <= maxy; j++)
			cout << board[i][j];
		cout << '\n';
	}
}

// n*m 공간의 섬의 한 칸이 세 변 이상이 바다(또는 맵 바깥)와 맞닿을 경우 50년 뒤 가라앉을 때, 50년 뒤의 상태를 테두리의 바다를 제거하고 출력하기

// 보드를 받고, 보드를 한 번 더 돌면서 땅을 만나면 땅과 맞닿은 바다가 몇 개인지 세기 - 이 시점에서 땅을 지우지 않기
// 이후 다시 한 번 보드를 돌면서 맞닿은 바다가 3개 이상인 땅을 발견하면 지우고, 안 지워지는 땅이라면 출력되는 맵 범위 잡기 - xy축의 최소/최대값 계산하기
// 이렇게 얻은 맵 범위에서 지도 출력하기
