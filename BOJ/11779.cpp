// 최소비용 구하기 2
// https://www.acmicpc.net/problem/11779

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
	vector<int> prev(n + 1, -1);
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
				prev[next] = cur;
				pq.push({ dist[next], next });
			}
		}
	}
	vector<int> res;
	int p = d;
	while (p != -1) {
		res.push_back(p);
		p = prev[p];
	}
	reverse(res.begin(), res.end());
	cout << dist[d] << '\n';
	cout << res.size() << '\n';
	for (int i : res)
		cout << i << ' ';
	cout << '\n';
}

// 요금이 다른 m개의 버스 노선으로 이어진 n개의 도시에서 두 도시 사이를 이동하려 할 때, 최소 비용으로 갈 수 있는 경로는?

// 최소비용 구하기 1에서 경로까지 구해야 하는 문제
// 현재 노드 바로 전 노드를 기억하는 배열을 만들어, 각 노드의 최단 거리를 갱신하는 순간 해당 노드의 전 노드를 갱신해주기
// 탐색이 끝나면 도착지부터 출발지까지 배열을 역으로 타서 결과 배열을 만든 뒤, 이를 뒤집어서 출력하기