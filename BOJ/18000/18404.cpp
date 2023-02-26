// 현명한 나이트
// https://www.acmicpc.net/problem/18404

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int sx, sy;
	cin >> sx >> sy;
	vector<vector<int>> board(n + 1, vector<int>(n + 1, -1));
	board[sx][sy] = 0;
	queue<pr> q;
	q.push({sx, sy});
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx <= 0 || yy <= 0 || xx > n || yy > n) {
				continue;
			}
			if (board[xx][yy] == -1) {
				board[xx][yy] = board[x][y] + 1;
				q.push({xx, yy});
			}
		}
	}
	for (int t = 0; t < m; t++) {
		int ex, ey;
		cin >> ex >> ey;
		cout << board[ex][ey] << ' ';
	}
	cout << '\n';
}

// n*n 보드에서 나이트가 각 말까지 이동하는 시간 구하기

// 평범한 bfs 문제 - 목표 말들이 여러 개 주어지지만 개별 거리만 구하면 되므로...
// 다만 매번 bfs를 새로 돌려주면 시간 초과 가능성 있음 - 그러므로 전체 보드에 대해 bfs 최단 거리를 구해둔 뒤 입력된 칸들의 결과 출력하기