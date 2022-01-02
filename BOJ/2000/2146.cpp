// 다리 만들기
// https://www.acmicpc.net/problem/2146

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	queue<prr> sq;
	int counter = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				counter++;
				queue<pr> q;
				q.push({ i, j });
				board[i][j] = counter;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					int c = 0;
					for (int i = 0; i < 4; i++) {
						int xx = x + dx[i];
						int yy = y + dy[i];
						if (xx < 0 || yy < 0 || xx >= n || yy >= n)
							continue;
						if (board[xx][yy] == 0)
							c++;
						else if (board[xx][yy] == 1) {
							board[xx][yy] = counter;
							q.push({ xx, yy });
						}
					}
					if (c != 0)
						sq.push({ {x, y}, counter });
				}
			}
		}
	}

	int res = 987654321;
	while (!sq.empty()) {
		int sx = sq.front().first.first;
		int sy = sq.front().first.second;
		int sc = sq.front().second;
		sq.pop();
		vector<vector<bool>> visit(n, vector<bool>(n));
		queue<prr> q;
		q.push({ {sx, sy}, 0 });
		visit[sx][sy] = true;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n || visit[xx][yy])
					continue;
				if (board[xx][yy] == 0) {
					visit[xx][yy] = true;
					q.push({ {xx, yy}, c + 1 });
				}
				else if (board[xx][yy] != sc) {
					if (res > c)
						res = c;
				}
			}
		}
	}
	cout << res << '\n';
}

// n*n 지도의 섬들 중 두 섬에 다리를 놓을 때, 놓을 수 있는 최소 거리는?

// 먼저 섬부터 판정 - bfs 집합 탐지를 통해 각 섬에 번호 부여
// 여기서는 입력으로 받은 board 배열에서 번호가 없는 땅은 1, 그렇지 않은 땅은 2 이상의 번호 부여
// 그러면서 다리를 놓을 수 있는 해안가 땅의 좌표와 섬 번호를 다리 탐색 큐에 삽입
// 이후 다리 탐색 큐를 하나씩 빼면서 해당 위치에서 놓을 수 있는 다리를 bfs 거리 탐지로 탐색
// 다리는 바다(0)를 건너 자신과 다른 땅에 도달했을때 놓았다고 판단 - 바다를 건널 때는 길이 추가해서 큐에 삽입, 같은 땅이면 패스, 다른 땅이면 다리 완성 판정
// 문제에서 원하는 건 다리의 길이이므로 다리가 완성되었을 때 지금까지 기록한 길이로 결과를 갱신