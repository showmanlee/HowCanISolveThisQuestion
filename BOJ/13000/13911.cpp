// 집 구하기
// https://www.acmicpc.net/problem/13911

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;
	vector<vector<pr>> board(v + 3);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}

	int m, mx;
	cin >> m >> mx;
	vector<int> mcd(m);
	for (int i = 0; i < m; i++)
		cin >> mcd[i];
	int s, sx;
	cin >> s >> sx;
	vector<int> stb(s);
	for (int i = 0; i < s; i++)
		cin >> stb[i];
	int mi = v + 1;
	int si = v + 2;
	for (int i = 0; i < m; i++)
		board[mi].push_back({ mcd[i], 0 });
	for (int i = 0; i < s; i++) 
		board[si].push_back({ stb[i], 0 });

	vector<int> dist_mcd(v + 3, 200000001), dist_stb(v + 3, 200000001);
	priority_queue<pr> pq;
	pq.push({ 0, mi });
	dist_mcd[mi] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (pr p : board[cur]) {
			int next = p.first;
			int ncost = p.second;
			if (dist_mcd[next] > cost + ncost) {
				dist_mcd[next] = cost + ncost;
				pq.push({ -dist_mcd[next], next });
			}
		}
	}
	pq.push({ 0, si });
	dist_stb[si] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (pr p : board[cur]) {
			int next = p.first;
			int ncost = p.second;
			if (dist_stb[next] > cost + ncost) {
				dist_stb[next] = cost + ncost;
				pq.push({ -dist_stb[next], next });
			}
		}
	}
	int res = 200000001;
	for (int i = 1; i <= v; i++) {
		if (dist_mcd[i] != 0 && dist_stb[i] != 0 && dist_mcd[i] <= mx && dist_stb[i] <= sx)
			res = min(res, dist_mcd[i] + dist_stb[i]);
	}
	if (res == 200000001)
		res = -1;
	cout << res << '\n';
}

// 맥도날드와 스타벅스가 곳곳에 있는 가중치 그래프 형태의 지도가 주어질 때, 맥도날드와 스타벅스와의 거리가 일정 이하면서 두 거리의 합이 최소인 집은?
// 각 노드에는 맥도날드, 스타벅스, 맥도날드/스타벅스, 집이 있을 수 있다

// 기본적으로 다익스트라 - 노드가 10000개이므로 노드마다 다익스트라를 돌리거나 플로이드를 돌릴 수는 없음
// 우리가 알고 싶은 것은 맥도날드와 스타벅스의 최단거리 - 이론적으로 맥도날드/스타벅스 전체에 대한 최단거리를 돌릴 수는 없나?
// 맥도날드와 스타벅스를 모두 묶어주는 가상의 노드를 만들어보자 - v+1, v+2번 노드는 맥도날드/스타벅스 전체를 가중치 0으로 이어준다
// 이렇게 처리하면 v+1, v+2는 모든 맥도날드/스타벅스에 무상으로 접근할 수 있고, 이를 통해 다익스트라 탐색을 확장하여 모든 맥도날드/스타벅스에 연결된 노드들에 접근해 최단거리를 구할 수 있다
// 모든 최단 거리를 구한 후 노드들을 순회하며 조건에 맞는 집인 경우 결과값을 갱신해준다 

// 더미 노드는 단순히 시작점과 기준의 역할을 하므로 양방향이 아닌 단방향으로 만들어주기 - 양방향으로 만들어줬더니 계속 틀리더라
// 양방향으로 만들어주면 특정 상황에서 다익스트라 탐색이 더미 노드로 돌아와버릴 수도 있음(?)