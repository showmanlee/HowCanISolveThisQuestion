// 특정한 최단 경로
// https://www.acmicpc.net/problem/1504

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int dijk(vector<vector<pr>> board, int n, int s, int d) {
	vector<int> dist(n + 1, -1);
	dist[s] = 0;
	priority_queue<pr> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (pr p : board[cur]) {
			int next = p.first;
			int ncost = p.second;
			if (dist[next] == -1 || dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
	return dist[d];
}

int main(void) {
	int n, e;
	cin >> n >> e;
	vector<vector<pr>> board(n + 1, vector<pr>());
	for (int i = 0; i < e; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		board[x].push_back({ y, l });
		board[y].push_back({ x, l });
	}
	int a, b;
	cin >> a >> b;
	int a1 = dijk(board, n, 1, a), b1 = dijk(board, n, 1, b);
	int a2 = dijk(board, n, a, b), b2 = dijk(board, n, b, a);
	int a3 = dijk(board, n, b, n), b3 = dijk(board, n, a, n);
	int resa = a1 + a2 + a3, resb = b1 + b2 + b3;
	if (a1 == -1 || a2 == -1 || a3 == -1)
		resa = -1;
	if (b1 == -1 || b2 == -1 || b3 == -1)
		resb = -1;
	if (resa == -1 || resb == -1)
		cout << (resa == -1 ? resb : resa) << '\n';
	else
		cout << (resa < resb ? resa : resb) << '\n';
}

// 무방향 그래프에서 1에서 시작해 특정한 두 정점을 거쳐서 n까지 이동하는 최단 경로의 길이 출력하기
// 경우의 수는 1->a->b->n 또는 1->b->a->n
// 1->a, 1->b, a->b, b->a, a->n, b->n 등 6가지 경우에 대한 다익스트라를 돌려 각각의 최단 거리 확인 후 최단거리 결정하기
// 도로가 없을 수 있으니 주의 - 셋 중 하나 이상의 경로가 없으면 -1 출력
// 다익스트라 부분을 함수로 떼서 처리