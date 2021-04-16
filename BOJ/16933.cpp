// 벽 부수고 이동하기 3
// https://www.acmicpc.net/problem/16933

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> prrr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(k + 1)));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	queue<prrr> q;
	q.push({ {0, 0}, {1, 0} });
	visit[0][0][0] = true;
	int res = -1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int broke = q.front().second.second;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			res = dist;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (board[xx][yy] == '0' && !visit[xx][yy][broke]) {
				visit[xx][yy][broke] = true;
				q.push({ {xx, yy}, {dist + 1, broke} });
			}
			if (broke < k && board[xx][yy] == '1' && !visit[xx][yy][broke + 1]) {
				if (dist % 2 == 1) {
					visit[xx][yy][broke + 1] = true;
					q.push({ {xx, yy}, {dist + 1, broke + 1} });
				}
				else
					q.push({ {x, y}, {dist + 1, broke} });
			}
		}
	}
	cout << res << '\n';
}

// n*m 보드에서 좌측 상단부터 우측 하단까지 이동하는데 최대 k개의 벽을 깰 수 있는데, 각 행동(이동, 파괴, 대기)을 할 때마다 낮밤이 바뀌고 밤에는 벽을 깰 수 없을 때, 최단 경로(행동 수)는?
// 벽 부수고 이동하기 2에 낮밤 개념이 추가됨 - dist % 2 == 1이면 낮, 아니면 밤
// 일반적인 상황에서는 멈추는 것이 의미가 없음 - 하지만 밤에 벽을 부수기 위해서 대기하는 상황이라면 의미가 있음
// 따라서 대기하는 상황은 벽을 부술 수 있는 상황에서 밤일 때 적용하기 - 이동하지 않는 대신, 이동 거리를 하나 늘려서 큐에 삽입
// 나머지 원리는 2와 동일