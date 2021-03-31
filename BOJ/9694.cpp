// 무엇을 아느냐가 문제가 아니라 누구를 아느냐가 문제다
// https://www.acmicpc.net/problem/9694

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n, m;
		cin >> n >> m;
		vector<vector<pr>> board(m);
		vector<int> dist(m, 987654321);
		vector<int> prev(m, -1);
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			board[a].push_back({ b, c });
			board[b].push_back({ a, c });
		}
		priority_queue<pr> pq;
		pq.push({ 0, 0 });
		dist[0] = 0;
		while (!pq.empty()) {
			int len = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (pr p : board[cur]) {
				if (dist[p.first] > len + p.second) {
					dist[p.first] = len + p.second;
					prev[p.first] = cur;
					pq.push({ -dist[p.first], p.first });
				}
			}
		}
		cout << "Case #" << tt << ": ";
		if (dist[m - 1] == 987654321)
			cout << -1;
		else {
			vector<int> res;
			int idx = m - 1;
			while (idx != -1) {
				res.push_back(idx);
				idx = prev[idx];
			}
			for (int i = res.size() - 1; i >= 0; i--)
				cout << res[i] << ' ';
		}
		cout << '\n';
	}
}

// 각 정치인 간 관계와 친밀도가 주어질 때, 0번부터 m-1번까지 도달하는 최소 거리의 경로는?
// 다익스트라 + 경로 출력
// 내 이전 인덱스를 저장하는 배열을 만들어 다익스트라 갱신 타이밍에 해당 배열도 같이 갱신되도록 설정
// 탐색 종료 후 해당 배열의 m-1번부터 역순으로 타고 올라가면 경로가 됩니다
// 물론 dist[m - 1] == INF일 경우에는 없으니 -1 출력하고