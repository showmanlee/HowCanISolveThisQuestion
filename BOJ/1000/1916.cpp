// 최소비용 구하기
// https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<long long, int> prl;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pr>> board(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
	}
	int s, d;
	cin >> s >> d;
	vector<long long> dist(n + 1, 100000000001);
	priority_queue<prl, vector<prl>, greater<prl>> pq;
	dist[s] = 0;
	pq.push({ dist[s], s });
	while (!pq.empty()) {
		long long cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)
			continue;
		for (pr p : board[cur]) {
			int next = p.first;
			long long ncost = p.second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ dist[next], next });
			}
		}
	}
	cout << dist[d] << '\n';
}

// 요금이 다른 m개의 버스 노선으로 이어진 n개의 도시에서 두 도시 사이를 이동하려 할 때, 최소 비용은?

// 기본적인 다익스트라 문제 - 버스가 단방향임에 주의
// 시간 제한이 짧으니 가지치기 필요 - pq에서 탐색할 도시의 '현재' 거리가 '갱신된' 거리보다 길 경우 중복 탐색하지 않기
// 이를 유의하면 일반적인 다익스트라로 해결 가능