// 3인통화
// https://www.acmicpc.net/problem/2398

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

	int n, m;
	cin >> n >> m;
	vector<vector<pr>> board(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	vector<int> beg(3);
	for (int i = 0; i < 3; i++)
		cin >> beg[i];
	vector<vector<int>> dist(3, vector<int>(n + 1, 98765432));
	vector<vector<int>> prev(3, vector<int>(n + 1, -1));
	priority_queue<pr> pq;
	for (int t = 0; t < 3; t++) {
		pq.push({ 0, beg[t] });
		dist[t][beg[t]] = 0;
		while (!pq.empty()) {
			int len = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (len > dist[t][cur])
				continue;
			for (pr p : board[cur]) {
				int next = p.first;
				int nlen = p.second + len;
				if (dist[t][next] > nlen) {
					dist[t][next] = nlen;
					pq.push({ -nlen, next });
					prev[t][next] = cur;
				}
			}
		}
	}
	int res = 2100000000, resi = 0;
	for (int i = 1; i <= n; i++) {
		if (res > dist[0][i] + dist[1][i] + dist[2][i]) {
			res = dist[0][i] + dist[1][i] + dist[2][i];
			resi = i;
		}
	}
	vector<pr> resv;
	for (int t = 0; t < 3; t++) {
		int idx = resi;
		while (idx != -1) {
			if (prev[t][idx] != -1)
				resv.push_back({ prev[t][idx], idx });
			idx = prev[t][idx];
		}
	}
	cout << res << ' ' << resv.size() << '\n';
	for (pr p : resv)
		cout << p.first << ' ' << p.second << '\n';
}

// 비용이 다른 전화선으로 이어진 n개의 지점 중 3개가 서로 연결될 때, 최소 비용은?

// 3개에서 출발하여 만나는 중간 지점(출발 지점들 중 하나일 수도 있음)까지의 거리의 합을 구한 후, 이들의 합으로 최단 중간 지점을 찾아낸다
// 이를 위해 다익스트라를 3번 돌려야 함 - 당연히 최단 거리 배열도 3개 나오고
// 여기에 최단거리 갱신 시 해당 거리의 이전 노드를 저장하는 배열을 갱신시키고, 마지막에 중간 지점에서 세 방향으로 회귀하면서 구성된 간선들을 저장하고 출력한다
// 간선의 순서 및 노드 정렬은 필요없음