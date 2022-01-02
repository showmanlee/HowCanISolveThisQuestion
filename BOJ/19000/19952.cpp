// 인성 문제 있어??
// https://www.acmicpc.net/problem/19952

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> prr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		int h, w, o, f, xs, ys, xe, ye;
		cin >> h >> w >> o >> f >> xs >> ys >> xe >> ye;
		vector<vector<int>> board(h + 1, vector<int>(w + 1));
		for (int i = 0; i < o; i++) {
			int x, y, l;
			cin >> x >> y >> l;
			board[x][y] = l;
		}
		vector<vector<bool>> visit(h + 1, vector<bool>(w + 1));
		visit[xs][ys] = true;
		queue<prr> q;
		q.push({ {xs, ys}, f });
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int force = q.front().second;
			q.pop();
			if (force == 0)
				continue;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 1 || yy < 1 || xx > h || yy > w)
					continue;
				if (!visit[xx][yy]) {
					if (board[xx][yy] - board[x][y] <= force) {
						visit[xx][yy] = true;
						q.push({ {xx, yy}, force - 1 });
					}
				}
			}
		}
		cout << (visit[xe][ye] ? "잘했어!!" : "인성 문제있어??") << '\n';
	}
}

// 장애물이 있는 보드에서 힘이 남아있을 때 출발 위치에서 도착 위치까지 도달할 수 있는가?
// 움직일 때는 힘이 1 소모되고, 자신보다 높은 장애물에 도달하기 위해서는 남아있는 힘이 높이차보다 크거나 같아야 한다(소모되는 힘은 같음)
// 남은 힘까지 체크하는 bfs