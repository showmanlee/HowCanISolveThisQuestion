// 두 단계 최단 경로 2
// https://www.acmicpc.net/problem/23801

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
	vector<int> points(t);
	for (int i = 0; i < t; i++) {
		cin >> points[i];
	}
	vector<long long> dist(n + 1, 98765432198765);
	priority_queue<pr> pq;
	pq.push({ 0, x });
	dist[x] = 0;
	while (!pq.empty()) {
		long long len = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < len) {
			continue;
		}
		for (pr p : board[cur]) {
			int next = p.second;
			long long nlen = p.first + len;
			if (dist[next] > nlen) {
				dist[next] = nlen;
				pq.push({ -nlen, next });
			}
		}
	}
	vector<long long> dist_inv(n + 1, 98765432198765);
	pq.push({ 0, z });
	dist_inv[z] = 0;
	while (!pq.empty()) {
		long long len = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist_inv[cur] < len) {
			continue;
		}
		for (pr p : board[cur]) {
			int next = p.second;
			long long nlen = p.first + len;
			if (dist_inv[next] > nlen) {
				dist_inv[next] = nlen;
				pq.push({ -nlen, next });
			}
		}
	}
	long long res = 987654321987650;
	for (int i : points) {
		res = min(res, dist[i] + dist_inv[i]);
	}
	if (res >= 98765432198765) {
		res = -1;
	}
	cout << res << '\n';
}

// 간선 간 거리가 다른 양방향 그래프에서 x에서 z까지 이동하는데 t개의 중간 지점 중 하나 이상을 거친 최단 거리는?

// 다익스트라를 t번 돌려야할 것 같지만 사실 2번만 돌려도 됨 - 정확히 하나를 거쳐야 하는 게 아니므로
// x에서 출발하는 다익스트라 + z에서 출발하는 다익스트라
// 이 결과를 바탕으로 x에서 중간점까지, z에서 중간점까지의 거리 합 중 최솟값을 출력한다 - 그게 답
// 중간점을 거친 최단 거리는 곧 중간점에서 양 끝점까지의 최단 거리의 합으로 볼 수 있으므로