// 녹색 옷 입은 애가 젤다지?
// https://www.acmicpc.net/problem/4485

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

	int no = 0;
	while (true) {
		no++;
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<vector<int>> board(n, vector<int>(n));
		vector<vector<int>> dist(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		dist[0][0] = board[0][0];
		priority_queue<prr> pq;
		pq.push({ -dist[0][0], {0, 0} });
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
				if (dist[xx][yy] == -1 || dist[xx][yy] > cost + board[xx][yy]) {
					dist[xx][yy] = cost + board[xx][yy];
					pq.push({ -dist[xx][yy], {xx, yy} });
				}
			}
		}
		cout << "Problem " << no << ": " << dist[n - 1][n - 1] << '\n';
	}
}

// 도둑루피들이 가득한 정사각형 동굴을 지날 때 최소로 잃는 돈은?
// 2차원 배열에서의 다익스트라 문제
// 다익스트라를 2차원 배열에 적용시켜봅시다 - dx, dy, xx, yy