// 거의 최단 경로
// https://www.acmicpc.net/problem/5719

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		int s, d;
		cin >> s >> d;
		vector<vector<pr>> board(n);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			board[a].push_back({ b, c });
		}
		vector<vector<int>> prev(n);
		vector<int> dist(n, 987654321);
		priority_queue<pr> pq;
		dist[s] = 0;
		pq.push({ 0, s });
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (cost > dist[cur])
				continue;
			for (pr p : board[cur]) {
				int next = p.first;
				int ncost = p.second;
				if (dist[next] > cost + ncost) {
					dist[next] = cost + ncost;
					prev[next].clear();
					pq.push({ -dist[next], next });
				}
				if (dist[next] == cost + ncost)
					prev[next].push_back(cur);
			}
		}
		vector<vector<bool>> used(n, vector<bool>(n));
		queue<int> q;
		q.push(d);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int i : prev[p]) {
				if (used[i][p])
					continue;
				used[i][p] = true;
				q.push(i);
			}
		}
		fill(dist.begin(), dist.end(), 987654321);
		dist[s] = 0;
		pq.push({ 0, s });
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (cost > dist[cur])
				continue;
			for (pr p : board[cur]) {
				int next = p.first;
				int ncost = p.second;
				if (used[cur][next])
					continue;
				if (dist[next] > cost + ncost) {
					dist[next] = cost + ncost;
					pq.push({ -dist[next], next });
				}
			}
		}
		int res = dist[d];
		if (res == 987654321)
			res = -1;
		cout << res << '\n';
	}
}

// 단방향 도로로 이루어진 보드에서 특정 지점 간의 최단 경로를 구성하는 도로를 뺀 나머지 도로만으로 만들 수 있는 최단 경로의 길이는?

// 최단 경로를 구해 그 경로를 이루는 간선들을 '제거'한 뒤, 나머지 간선들로 '거의 최단 경로'를 만들어주면 됨 - 다익스트라 두 번
// 각 지점간 간선은 하나 이하임이 보장됨 - 그러나 최단 경로 및 거의 최단 경로가 하나뿐임은 보장되지 않음
// 따라서 여러 개일 수 있는 최단 경로를 모두 캐치해두어야 함

// 우선 첫 번째 다익스트라에서는 최단경로(들)을 체크
// 여기서 현재 노드로 오는 이전 노드(들)을 체크하는 2차원 배열을 만들어, 현재 노드까지의 최단 거리가 갱신되는 순간 해당 칸의 배열을 초기화 후 이전 노드 삽입하기
// 만약 현재 노드까지의 최단 거리가 기록된 거리와 같은 경우(= 최단 거리가 2개 이상이 된 경우)에는 초기화하지 않고 이전 노드 삽입하기
// 이렇게 다익스트라와 함께 이전 노드 배열을 관리하면, 마지막에는 최단 거리를 구성하는 노드들이 남게 됨 - 다익스트라 최단 거리는 각 노드까지의 최단 거리로 구성되니까
// 이 배열을 bfs로 도착지부터 bfs로 순회하며 발견하는 간선 제거 - 간선 제거 판정은 [출발][도착]으로 나타내는 2차원 bool 배열을 체크해주는 걸로
// 마지막으로 dist 배열 재초기화 후 체크한 간선을 무시하고 다익스트라를 돌려서 도착지까지의 최단 거리가 나오는지 확인하기