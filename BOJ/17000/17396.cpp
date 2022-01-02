// 백도어
// https://www.acmicpc.net/problem/17396

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<long long, int> prl;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> seen(n);
	vector<vector<prl>> board(n);
	for (int i = 0; i < n; i++)
		cin >> seen[i];
	seen[n - 1] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (seen[a] || seen[b])
			continue;
		board[a].push_back({ c, b });
		board[b].push_back({ c, a });
	}
	vector<long long> dist(n, 98765432198765);
	dist[0] = 0;
	priority_queue<prl> pq;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		long long len = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (len > dist[cur])
			continue;
		for (prl p : board[cur]) {
			long long nlen = p.first;
			int next = p.second;
			if (dist[next] > len + nlen) {
				dist[next] = len + nlen;
				pq.push({ -dist[next], next });
			}
		}
	}
	if (dist[n - 1] == 98765432198765)
		dist[n - 1] = -1;
	cout << dist[n - 1] << '\n';
}

// 우리 넥서스(0)에서 상대 넥서스(n - 1)까지 가는데 n-3개(1~n-2)의 분기점이 있고, 그 중 몇 개의 분기점은 적에게 보일 때, 적에게 들키지 않고 적 넥서스까지 가는 최소 거리는?

// 기본적으로 다익스트라 - 그런데 적에게 보이는 분기점으로는 아예 가면 안 됨(적 넥서스 제외)
// 따라서 앞서 받은 분기점 정보를 바탕으로 경로를 받을 때 적에게 보이는 분기점이 포함된 경우 아예 vector에 그리지 않도록 설정
// 단, 적 넥서스는 필연적으로 보일 수밖에 없기에 체크되어 나오는 적 넥서스는 체크를 해제해주기
// 이렇게 만들어진 맵을 가지고 다익스트라를 돌려 dist[n - 1]을 출력하기
// 맵이 충분히 넓기 때문에(n = 100000, m = 300000) 시간 초과를 막기 위해서는 가지치기가 필요함 - 기록된 거리보다 누적 거리가 더 길다면 아예 탐색하지 않기
// 또한 dist를 long long으로 관리해야 함에 주의