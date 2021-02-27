// 미로만들기
// https://www.acmicpc.net/problem/2665

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> prr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	vector<vector<int>> dist(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
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
			if (xx < 0 || yy < 0 || xx >= n || yy >= n)
				continue;
			int cur = (board[xx][yy] == '0' ? 1 : 0);
			if (dist[xx][yy] == -1 || dist[xx][yy] > cost + cur) {
				dist[xx][yy] = cost + cur;
				pq.push({ -dist[xx][yy], {xx, yy} });
			}
		}
	}
	cout << dist[n - 1][n - 1] << '\n';
}

// 좌측 상단에서 우측 하단으로 가는 미로를 만들기 위해 없애야 하는 검정 칸의 최소 수는?
// 0, 1 가중치만 가진 2차원 다익스트라 문제
// 하얀 칸이 1로 표시되어 있음에 주의