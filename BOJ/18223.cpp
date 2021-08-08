// 민준이와 마산 그리고 건우
// https://www.acmicpc.net/problem/18223

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e, p;
	cin >> v >> e >> p;
	vector<vector<pr>> board(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	vector<vector<int>> prev(v + 1);
	vector<int> dist(v + 1, 987654321);
	priority_queue<pr> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int len = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (pr t : board[cur]) {
			int next = t.first;
			int nlen = len + t.second;
			if (dist[next] > nlen) {
				prev[next].clear();
				dist[next] = nlen;
				pq.push({ -nlen, next });
			}
			if (dist[next] == nlen) {
				prev[next].push_back(cur);
			}
		}
	}
	bool res = false;
	queue<int> q;
	vector<bool> visit(v + 1);
	q.push(v);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == p) {
			res = true;
			break;
		}
		for (int t : prev[u]) {
			if (!visit[t]) {
				visit[t] = true;
				q.push(t);
			}
		}
	}
	cout << (res ? "SAVE HIM" : "GOOD BYE") << '\n';
}

// 가중치가 있는 양방향 그래프의 1번 노드에서 v번 노드까지 이동하는 최단 경로(들)에 p번 노드가 포함되어 있는가?

// 다익스트라로 최단 경로를 구해준 뒤, 그 최단 경로를 구성하는 노드들 중 p번 노드가 있는지 bfs로 확인하기
// 이를 위해 이전 최단 노드를 기록하는 prev는 2차원 vector로 구성해야 함 - 만약 최단 거리가 갱신될 경우 이전 노드 목록을 초기화하고, 그렇지 않다면 공동 최단 경로로 추가하기 위해
// 어쨌든 일반적인 방식으로 1부터 v까지의 최단 경로를 만들면 prev는 단방향 그래프의 형태를 띄게 됨 - 여기서 v부터 시작하는 bfs를 돌린다
// 최종적으로 bfs 탐색 중 p를 발견하면 가능, 그렇지 않으면 실패 판정