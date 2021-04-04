// 최소비용 구하기 2
// https://www.acmicpc.net/problem/11779

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pr>> board(n + 1);
	vector<pr> dist(n + 1, { -1, -1 });
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
	}
	int start, dest;
	cin >> start >> dest;
	dist[start] = { 0, 0 };
	priority_queue<pr> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		for (pr p : board[pos]) {
			if (dist[p.first].first == -1 || dist[p.first].first > cost + p.second) {
				dist[p.first].first = cost + p.second;
				dist[p.first].second = pos;
				pq.push({ -dist[p.first].first, p.first });
			}
		}
	}
	stack<int> res;
	res.push(dest);
	while (dist[res.top()].second > 0)
		res.push(dist[res.top()].second);
	cout << dist[dest].first << '\n' << res.size() << '\n';
	while (!res.empty()) {
		cout << res.top() << ' ';
		res.pop();
	}
	cout << '\n';
}

// 한 도시에서 다른 도시로 가는 최소 비용과 최소 경로의 길이, 그리고 그 경로 출력하기
// 다익스트라에서 가중치 바꾸는 과정에서 그 최소 경로가 어디서 왔는지도 기록한 후, 목적지부터 역순으로 경로 출력(스택)
// 결국 최단 경로 출력도 그렇게 어려운 건 아님 - 최소 경로가 어디서 왔는지만 알면 이어갈 수 있으니