// 두 단계 최단 경로 3
// https://www.acmicpc.net/problem/23807

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<long long, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pr>> board(n + 1, vector<pr>());
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		board[a].push_back({ c, b });
		board[b].push_back({ c, a });
	}
	int x, z;
	cin >> x >> z;
	int t;
	cin >> t;
	vector<int> points(t + 2);
	for (int i = 0; i < t; i++) {
		cin >> points[i];
	}
	points[t] = x;
	points[t + 1] = z;
	vector<vector<long long>> dist(t + 2, vector<long long>(n + 1, 98765432198765));
	priority_queue<pr> pq;
	for (int i = 0; i < t + 2; i++) {
		pq.push({ 0, points[i] });
		dist[i][points[i]] = 0;
		while (!pq.empty()) {
			long long len = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (dist[i][cur] < len) {
				continue;
			}
			for (pr p : board[cur]) {
				int next = p.second;
				long long nlen = p.first + len;
				if (dist[i][next] > nlen) {
					dist[i][next] = nlen;
					pq.push({ -nlen, next });
				}
			}
		}
	}
	long long res = 98765432198765 * 4;
	for (int t1 = 0; t1 < t; t1++) {
		for (int t2 = 0; t2 < t; t2++) {
			for (int t3 = 0; t3 < t; t3++) {
				if (t1 == t2 || t2 == t3 || t1 == t3) {
					continue;
				}
				res = min(res, dist[t][points[t1]] + dist[t1][points[t2]] + dist[t2][points[t3]] + dist[t3][z]);
			}
		}
	}
	if (res >= 98765432198765) {
		res = -1;
	}
	cout << res << '\n';
}

// 간선 간 거리가 다른 양방향 그래프에서 x에서 z까지 이동하는데 t개의 중간 지점 중 3개 이상을 거친 최단 거리는?

// 다행히 시간적 여유가 충분한 데다 t가 100개까지만 주어지므로 다익스트라를 t + 2번 돌려도 되는 상황
// 따라서 x, z, 모든 t에 대한 다익스트라를 돌린 후 3개의 t를 선택해 x-t1, t1-t2, t2-t3, t3-z의 거리를 구한다
// 물론 선택한 3개의 점이 중복되어서는 안 됨