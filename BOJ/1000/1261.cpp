// 알고스팟
// https://www.acmicpc.net/problem/1261

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(m, vector<char>(n));
	vector<vector<int>> dist(m, vector<int>(n, -1));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	dist[0][0] = 0;
	priority_queue<prr> pq;
	pq.push({ 0, {0, 0} });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= m || yy >= n)
				continue;
			if (dist[xx][yy] == -1 || dist[xx][yy] > cost + (board[xx][yy] - '0')) {
				dist[xx][yy] = cost + (board[xx][yy] - '0');
				pq.push({ -dist[xx][yy], {xx, yy} });
			}
		}
	}
	cout << dist[m - 1][n - 1] << '\n';
}

// 맵의 좌측 상단에서 우측 하단까지 도달하기 위해 최소 몇 개의 벽을 깨야 하는가?
// 벽이 없는 방끼리는 가중치 0, 벽이 있는 방으로는 가중치 1로 두는 변형 다익스트라 문제로 접근하자
// 가중치가 음이 아니면 써먹을 수 있는 pq 기반 알고리즘, 다익스트라 잊지 않았죠..?