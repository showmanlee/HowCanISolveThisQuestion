// 가장 먼 곳
// https://www.acmicpc.net/problem/22865

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> s(3);
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
	}
	int m;
	cin >> m;
	vector<vector<pr>> board(n + 1, vector<pr>());
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	vector<vector<int>> dist(n + 1, vector<int>(3, 1987654321));
	for (int t = 0; t < 3; t++) {
		priority_queue<pr> pq;
		pq.push({ 0, s[t] });
		dist[s[t]][t] = 0;
		while (!pq.empty()) {
			int len = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (pr p : board[cur]) {
				int next = p.first;
				int nlen = p.second + len;
				if (dist[next][t] > nlen) {
					dist[next][t] = nlen;
					pq.push({ -nlen, next });
				}
			}
		}
	}
	int res = 987654321;
	int resl = 0;
	for (int i = 1; i <= n; i++) {
		if (resl < min(dist[i][0], min(dist[i][1], dist[i][2]))) {
			resl = min(dist[i][0], min(dist[i][1], dist[i][2]));
			res = i;
		}
	}
	cout << res << '\n';
}

// 길이가 다른 m개의 양방향 도로로 이어진 n개의 집 중 친구 3명이 살고 있는 집에서 가장 먼 집 구하기

// '친구 3명과의 거리' = 각 친구의 집과 선택한 집의 거리 중 가장 가까운 거리
// 길이가 다른 길이 등장하기에 다익스트라를 이용해서 길이를 재줘야 함 - n이 10만까지이므로 3연속 다익스트라는 충분히 가능
// 이렇게 다익스트라를 세 번 돌리면 3개의 dist 배열이 나오고, 여기서 모든 집에 대해 가장 작은 값을 뽑아서 결과 만들기