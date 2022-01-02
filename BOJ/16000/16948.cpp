// 데스 나이트
// https://www.acmicpc.net/problem/16948

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[6] = { -2, -2 , 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> visit(n, vector<int>(n, -1));
	int xs, ys, xe, ye;
	cin >> xs >> ys >> xe >> ye;
	queue<pr> q;
	q.push({ xs, ys });
	visit[xs][ys] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == xe && y == ye)
			break;
		for (int i = 0; i < 6; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= n)
				continue;
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				q.push({ xx, yy });
			}
		}
	}
	cout << visit[xe][ye] << '\n';
}

// n*n 보드에서 6방향으로 움직이는 데스 나이트가 출발점에서 도착점으로 이동할 수 있는 최단 거리는?
// 6방향으로 움지깅는 BFS - 나이트 문제와 비슷