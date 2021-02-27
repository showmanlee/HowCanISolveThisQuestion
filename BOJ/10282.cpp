// 해킹
// https://www.acmicpc.net/problem/10282

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, d, c;
		cin >> n >> d >> c;
		vector<int> dist(n + 1, -1);
		vector<vector<pr>> network(n + 1);
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			network[b].push_back({ a, s });
		}
		dist[c] = 0;
		priority_queue<pr> pq;
		pq.push({ 0, c });
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int pos = pq.top().second;
			pq.pop();
			for (pr p : network[pos]) {
				if (dist[p.first] == -1 || dist[p.first] > p.second + cost) {
					dist[p.first] = p.second + cost;
					pq.push({ -dist[p.first], p.first });
				}
			}
		}
		int count = 0, max = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != -1) {
				count++;
				if (dist[i] > max)
					max = dist[i];
			}
		}
		cout << count << ' ' << max << '\n';
	}
}

// 단방향으로 의존된 컴퓨터가 연결된 네트워크 중 한 대에 바이러스를 심었을 때, 바이러스에 감염되는 컴퓨터 수와 마지막 컴퓨터가 감염된 시간 구하기
// 다익스트라 스타일로 가능한 모든 컴퓨터의 가중치를 갱신한 뒤 개수 세기