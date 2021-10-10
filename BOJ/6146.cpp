// 신아를 만나러
// https://www.acmicpc.net/problem/6146

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, n;
	cin >> a >> b >> n;
	vector<vector<int>> board(1001, vector<int>(1001)), visit(1001, vector<int>(1001, -1));
	board[a + 500][b + 500] = 2;
	for (int i = 0; i < n; i++) {
		int c, d;
		cin >> c >> d;
		board[c + 500][d + 500] = 1;
	}
	queue<pr> q;
	q.push({ 500, 500 });
	visit[500][500] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (board[x][y] == 2)
			break;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx > 1000 || yy > 1000 || board[xx][yy] == 1)
				continue;
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				q.push({ xx, yy });
			}
		}
	}
	cout << visit[a + 500][b + 500] << '\n';
}

// -500~500 좌표가 있는 2차원 좌표계의 n개의 칸들에 웅덩이가 있고, 목적지가 (a, b)에 있을 때, (0, 0)에서 출발해 상하좌우로 이동하며 웅덩이를 밟지 않고 목적지까지 이동하는 최단 거리는?

// 일반적인 bfs 최단거리 탐색
// 다만 여기서는 좌표계가 음수가 나온다 - 그래도 최소 범위가 정해져있으므로 원래 좌표값 + 500에 대응하여 일반적인 배열로도 풀 수 있음