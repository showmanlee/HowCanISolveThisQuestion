// 면접보는 승범이네
// https://www.acmicpc.net/problem/17835

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pr>> board(n + 1);
	vector<long long> dist(n + 1, 987654321987654);
	for (int i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		board[b].push_back({ a, c });
	}
	priority_queue<pr> pq;
	for (int i = 0; i < k; i++) {
		long long p;
		cin >> p;
		dist[p] = 0;
		pq.push({ 0, p });
	}
	while (!pq.empty()) {
		long long len = -pq.top().first;
		long long cur = pq.top().second;
		pq.pop();
		if (dist[cur] < len)
			continue;
		for (pr p : board[cur]) {
			long long next = p.first;
			long long nlen = len + p.second;
			if (dist[next] > nlen) {
				dist[next] = nlen;
				pq.push({ -nlen, next});
			}
		}
	}
	long long resi = 0, resn = 0;
	for (int i = 1; i <= n; i++) {
		if (resn < dist[i]) {
			resi = i;
			resn = dist[i];
		}
	}
	cout << resi << '\n' << resn << '\n';
}

// 길이가 다른 단방향 도로들로 이어진 n개의 도시 중 k개의 도시에 면접장을 놓았을 때, 면접장과의 거리가 가장 먼 도시와 그 거리는?

// 다중 위치와의 거리를 고려해야 하는 다익스트라 문제
// 그냥 도시에서 면접장(들)과의 거리를 재는 것은 비효율적 - 반대로 생각하면 면접장에서 각 도시와의 거리를 구해도 됨
// 따라서 처음에 도로들을 받을 때 반대 방향으로 저장하고, 다익스트라 pq에는 주어진 면접장들을 거리를 0으로 둬서 최초 삽입
// 이후 pq를 돌면서 거리들을 갱신하면 가장 가까운 면접장과의 거리가 구해지고, 구해진 거리들 중 최댓값이 나오는 도시를 구하고 출력하기