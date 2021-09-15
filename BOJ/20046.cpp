// Road Reconstruction
// https://www.acmicpc.net/problem/20046

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m)), dist(n, vector<int>(m, 987654321));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	dist[0][0] = board[0][0];
	priority_queue<prr> pq;
	if (dist[0][0] != -1)
		pq.push({ -dist[0][0], {0, 0} });
	while (!pq.empty()) {
		int len = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (x == n - 1 && y == m - 1)
			break;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == -1)
				continue;
			if (dist[xx][yy] > len + board[xx][yy]) {
				dist[xx][yy] = len + board[xx][yy];
				pq.push({ -dist[xx][yy], {xx, yy} });
			}
		}
	}
	if (dist[n - 1][m - 1] == 987654321)
		dist[n - 1][m - 1] = -1;
	cout << dist[n - 1][m - 1] << '\n';
}

// n*m 보드에 미이 도로가 놓인 곳, 도로를 놓는데 비용이 1/2 드는 곳, 도로를 못 놓는 곳이 있을 때, 좌측 상단에서 우측 하단까지 도로를 놓는데 필요한 최소 비용은?

// 2차원 환경에서의 다익스트라
// 2차원 최단거리 탐색 bfs와 동일한 원리로 작동하지만, 알고리즘을 pq 기반 다익스트라로 적용해야 함 - 현재 길이 + 다음 칸 비용이 기록된 최소 비용보다 낮은 경우, 해당 값으로 갱신하며 pq에 삽입
// 그렇게 돌다가 우측 하단에 도달하면 탐색을 종료하고 해당 최소 비용 출력하기
// 다만 시작점과 끝점에 도로가 놓여있음이 보장되지 않음 - -1일 수도 있음
// 끝점은 이동하면서 자연스럽게 반영이 되고, 시작점의 경우 -1인 경우를 빼고 그 칸에 적힌 비용을 초기 최소 비용과 pq에 반영하도록 설정