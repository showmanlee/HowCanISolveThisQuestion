// A spiral walk
// https://www.acmicpc.net/problem/5976

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n + 2, vector<int>(n + 2));
	for (int i = 1; i <= n; i++) {
		v[i][0] = v[i][n + 1] = v[0][i] = v[n + 1][i] = 987654321;
	}
	int x = 1, y = 1;
	int dir = 0;
	for (int i = 1; i <= n * n; i++) {
		v[x][y] = i;
		x += dx[dir];
		y += dy[dir];
		if (v[x][y] != 0) {
			x -= dx[dir];
			y -= dy[dir];
			dir = (dir + 1) % 4;
			x += dx[dir];
			y += dy[dir];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

// n*n 보드에 1부터 n*n까지 시계방향 나선형으로 채워진 형태 그리기

// 적당히 계산해서 그려봅니다 - 조건 단순화를 위해 상하좌우로 1칸씩 더 확보해서 임의의 수를 채워 넣어서 채워봅시다