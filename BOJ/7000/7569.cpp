// 토마토
// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class coord {
public:
	int x, y, z;
	coord(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	coord operator+(coord c) {
		int xx = x + c.x;
		int yy = y + c.y;
		int zz = z + c.z;
		return coord(xx, yy, zz);
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, h;
	cin >> m >> n >> h;
	vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m)));
	queue<coord> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
					q.push(coord(i, j, k));
			}
		}
	}
	coord dc[6] = { coord(0, 0, 1), coord(0, 0, -1), coord(0, 1, 0), coord(0, -1, 0), coord(1, 0, 0), coord(-1, 0, 0) };
	int max = 0;
	while (!q.empty()) {
		coord c = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			coord cc = c + dc[i];
			if (cc.x < 0 || cc.y < 0 || cc.z < 0 || cc.x >= h || cc.y >= n || cc.z >= m)
				continue;
			if (box[cc.x][cc.y][cc.z] == 0) {
				box[cc.x][cc.y][cc.z] = box[c.x][c.y][c.z] + 1;
				if (box[cc.x][cc.y][cc.z] - 1 > max)
					max = box[cc.x][cc.y][cc.z] - 1;
				q.push(cc);
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0;
				}
			}
	}
	cout << max << '\n';
	return 0;
}

// 3D BFS 문제
// 3축에 대한 인덱스를 잘 잡아줘야 함(가로, 세로, 높이 순으로 주어짐)