// 최단경로
// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, start;
	cin >> n >> m >> start;
	vector<vector<pair<int, int>>> vertex(n + 1, vector<pair<int, int>>());
	vector<int> dist(n + 1, -1);
	vector<bool> visit(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(b, c));
	}

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		for (int i = 0; i < vertex[current].size(); i++) {
			int nCost = vertex[current][i].second;
			int next = vertex[current][i].first;
			if (dist[next] == -1 || dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (dist[i] < 0)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
}

// 다익스트라 알고리즘 - 음수가 아닌 가중치가 있는 그래프에서 최단 경로 찾기
// 0. 각 노드와 시작 노드 간의 거리를 저장하는 배열 만들어두기(초기값은 INF)
// 1. 시작 노드와 직접적으로 연결된 모든 정점들의 거리를 저장하고, 시작 노드를 방문 노드로 세팅한다.
// 2. 방문한 노드와 연결되어 있는 노드 중 거리가 가장 짧은 노드를 선택해 해당 노드를 방문 노드로 세팅한다.
// 3. 만약 2.에서 방문한 노드와 연결된 노드가 거쳐가는 경우 더 짧은 거리일 때, 거리를 갱신해준다.
// 접근할 수 있는 노드를 모두 방문할 때까지 2~3을 반복한다.
// (방문 노드로 세팅한다 = 거리 배열에서 INF를 실제 거리값으로 대체한다

// 따라서 특성 상 우선순위 큐(priority_queue)를 사용해야 함
// 별도의 세팅이 없는 한 priority_queue는 최소 힙이기 때문에 최대 힙으로 바꾸려면 음수로 만들어 넣어줘야 함(별도의 함수를 쓰지 않는 한)
// + pair로 priority_queue 만들 때는 앞쪽 먼저 정렬하므로 앞쪽에 거리값을 두기(별도의 함수를 쓰지 않는 한)
// queue와 달리 가장 앞의 원소가 front가 아닌 top임에 유의

// 시작 노드를 인덱스로 pair(도착, 가중치)가 저장된 이중 vector로 edge 저장
// 게임 업계에서 반드시 필요한 알고리즘이니 반드시 숙지할 것
