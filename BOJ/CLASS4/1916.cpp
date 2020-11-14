// 최소비용 구하기
// https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<int> dist(n + 1, -1);
	vector<vector<pair<int, int>>> vertex(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(c, b));
	}
	int start, end;
	cin >> start >> end;

	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < vertex[cur].size(); i++) {
			int nCost = vertex[cur][i].first;
			int next = vertex[cur][i].second;
			if (dist[next] == -1 || dist[next] > nCost + cost) {
				dist[next] = nCost + cost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	cout << dist[end] << '\n';
}

// 또 다른 다익스트라 문제
// 이번엔 출발점과 도착점이 주어짐 - 그러나 다익스트라 특성 상(거쳐 가는 것이 더 빠르냐, 지금까지 본 루트가 더 빠르냐를 봄) 전체 노드에 대한 거리 저장이 필요함