// 두 단계 최단 경로 1
// https://www.acmicpc.net/problem/23793

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pr>> board(n + 1, vector<pr>());
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
	}
	int x, y, z;
	cin >> x >> y >> z;
	vector<int> start = { x, y };
	vector<vector<int>> dist(n + 1, vector<int>(2, 1987654321));
	for (int t = 0; t < 2; t++) {
		priority_queue<pr> pq;
		pq.push({ 0, start[t] });
		dist[start[t]][t] = 0;
		while (!pq.empty()) {
			int len = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (len > dist[cur][t]) {
				continue;
			}
			for (pr p : board[cur]) {
				int next = p.first;
				int nlen = p.second + len;
				if (dist[next][t] > nlen) {
					dist[next][t] = nlen;
					pq.push({ -nlen, next });
				}
			}
		}
	}
	vector<int> dist_t(n + 1, 1987654321);
	priority_queue<pr> pq;
	pq.push({ 0, x });
	dist_t[x] = 0;
	while (!pq.empty()) {
		int len = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (len > dist_t[cur]) {
			continue;
		}
		for (pr p : board[cur]) {
			int next = p.first;
			int nlen = p.second + len;
			if (next == y) {
				continue;
			}
			if (dist_t[next] > nlen) {
				dist_t[next] = nlen;
				pq.push({ -nlen, next });
			}
		}
	}
	cout << (dist[y][0] == 1987654321 || dist[z][1] == 1987654321 ? -1 : dist[y][0] + dist[z][1]) << ' ' << (dist_t[z] == 1987654321 ? -1 : dist_t[z]) << '\n';
}

// 간선 간 거리가 다른 단방향 그래프에서 출발 지점에서 도착 지점까지 가는데 중간 지점을 거쳐서 가는 거리와 그렇지 않은 거리 출력하기

// x에서 y까지 다익스트라 + y에서 z까지 다익스트라 vs x에서 z까지 다익스트라
// x에서 z까지 다익스트라를 구할 때 y를 거쳐서는 안 됨 - 만약 유일한 최단 경로가 y를 거치게 된다면 -1을 출력해야 함
// 따라서 다익스트라를 3번 돌려야 함 - x-y + y-z vs x-z인데 y에 도달해서는 안 되는 다익스트라
// 시간 제한이 0.3초로 넉넉하지 않음 - pq에서 찌꺼기 스택인 경우 continue
// 이렇게 하면 세 번의 다익스트라를 돌릴 수 있음