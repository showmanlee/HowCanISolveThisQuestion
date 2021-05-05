// 상범 빌딩
// https://www.acmicpc.net/problem/6593

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int> tpi4;
int dx[6] = { -1, 0, 0, 1, 0, 0 };
int dy[6] = { 0, -1, 0, 0, 1, 0 };
int dz[6] = { 0, 0, -1, 0, 0, 1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;
		vector<vector<vector<char>>> board(l, vector<vector<char>>(r, vector<char>(c)));
		int sx, sy, sz, gx, gy, gz;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						sx = i;
						sy = j;
						sz = k;
					}
					else if (board[i][j][k] == 'E') {
						gx = i;
						gy = j;
						gz = k;
					}
				}
			}
		}
		vector<vector<vector<bool>>> visit(l, vector<vector<bool>>(r, vector<bool>(c)));
		queue<tpi4> q;
		q.push({ sx, sy, sz, 0 });
		visit[sx][sy][sz] = true;
		int res = -1;
		while (!q.empty()) {
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int z = get<2>(q.front());
			int t = get<3>(q.front());
			q.pop();
			if (x == gx && y == gy && z == gz) {
				res = t;
				break;
			}
			for (int i = 0; i < 6; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				int zz = z + dz[i];
				if (xx < 0 || yy < 0 || zz < 0 || xx >= l || yy >= r || zz >= c || visit[xx][yy][zz])
					continue;
				if (board[xx][yy][zz] != '#') {
					visit[xx][yy][zz] = true;
					q.push({ xx, yy, zz, t + 1 });
				}
			}
		}
		if (res != -1)
			cout << "Escaped in " << res << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
}

// r*c 보드가 l층 쌓인 규모의 빌딩에서 탈출할 수 있는가? 있다면 얼마나 걸리는가?
// 3차원 bfs 활용하기 - 층간 이동은 각 층의 동일한 칸이 바어있는 경우에 가능
// bfs 순회하면서 시간도 재기 - 탈출하면 시간을 결과값으로 삼기