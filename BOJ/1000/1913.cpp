// 달팽이
// https://www.acmicpc.net/problem/1913

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, f;
	cin >> n >> f;
	vector<vector<int>> p(n, vector<int>(n));
	int x = -1, y = 0, len = n, dir = 0;
	int tx = -1, ty = -1;
	int count = n * n + 1;
	while (count > 1) {
		if (dir == 0) {
			for (int i = 0; i < len; i++) {
				p[++x][y] = --count;
				if (count == f) {
					tx = x;
					ty = y;
				}
			}
		}
		else if (dir == 1) {
			for (int i = 0; i < len; i++) {
				p[x][++y] = --count;
				if (count == f) {
					tx = x;
					ty = y;
				}
			}
		}
		else if (dir == 2) {
			for (int i = 0; i < len; i++) {
				p[--x][y] = --count;
				if (count == f) {
					tx = x;
					ty = y;
				}
			}
		}
		else if (dir == 3) {
			for (int i = 0; i < len; i++) {
				p[x][--y] = --count;
				if (count == f) {
					tx = x;
					ty = y;
				}
			}
		}
		dir = (dir + 1) % 4;
		if (dir % 2 == 1)
			len--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << p[i][j] << ' ';
		cout << endl;
	}
	cout << (tx + 1) << ' ' << (ty + 1) << endl;
}

// 정방향으로 넣는 게 힘들면 역방향으로