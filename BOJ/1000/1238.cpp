// 파티
// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pq;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<int>> route(n + 1, vector<int>(n + 1, -1));
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		route[a][b] = c;
	}
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		priority_queue<pq> pq;
		pq.push({ 0, i });
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (int j = 1; j <= n; j++) {
				if (cur != j && route[cur][j] != -1) {
					if (dist[i][j] == -1 || dist[i][j] > cost + route[cur][j]) {
						dist[i][j] = cost + route[cur][j];
						pq.push({ -dist[i][j], j });
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (res < dist[i][x] + dist[x][i])
			res = dist[i][x] + dist[x][i];
	}
	cout << res << '\n';
}

// 거리가 다른 단방향 도로들로 이어진 마을들이 있을 때, 자신의 마을에서 특정 마을에 갔다가 돌아오는 최단 경로가 가장 긴 사람의 소요 시간은?
// 모든 노드에 대한 모든 최단 경로가 필요 - 모든 집에 대해 다익스트라를 돌려볼까?
// 그럼 결과는 2차원 배열의 형태로 나오겠지 - 헷갈리지 않게 조심
// 플로이드는 편리하지만 오래 걸리는 알고리즘 - 1000개가 주어지는 여기서는 사용하기 조심스러움