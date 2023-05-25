// 달팽이2
// https://www.acmicpc.net/problem/1952

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> visit(n, vector<bool>(m));
	int x = 0, y = 0, dir = 0;
	int res = 0, cnt = 0;
	while (true) {
		if (!visit[x][y]) {
			visit[x][y] = true;
			cnt++;
		}
		if (cnt == n * m) {
			break;
		}
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || y < 0 || x >= n || y >= m || visit[x][y]) {
			x -= dx[dir];
			y -= dy[dir];
			dir = (dir + 1) % 4;
			res++;
		}
	}
	cout << res << '\n';
}

// n*m 보드에서 달팽이가 좌측 상단에서부터 달팽이 모양으로 보드를 순회할 때, 방향이 꺾이는 횟수 구하기

// 직접 돌려가면서 구해볼 수 있음 - 중단점은 모든 칸을 돌았을 때