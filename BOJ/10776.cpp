// 제국
// https://www.acmicpc.net/problem/10776

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, n, m;
	cin >> k >> n >> m;
	vector<vector<prr>> route(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, t, h;
		cin >> a >> b >> t >> h;
		route[a].push_back({ {t, h}, b });
		route[b].push_back({ {t, h}, a });
	}
	int beg, dest;
	cin >> beg >> dest;
	vector<vector<int>> dist(n + 1, vector<int>(k + 1, 987654321));
	dist[beg][k] = 0;
	priority_queue<prr> pq;
	pq.push({ {0, k}, beg });
	int res = -1;
	while (!pq.empty()) {
		int len = -pq.top().first.first;
		int remain = pq.top().first.second;
		int cur = pq.top().second;
		pq.pop();
		if (cur == dest) {
			res = len;
			break;
		}
		for (prr p : route[cur]) {
			int nlen = p.first.first;
			int ncut = p.first.second;
			int next = p.second;
			if (remain - ncut > 0 && dist[next][remain - ncut] > len + nlen) {
				dist[next][remain - ncut] = len + nlen;
				pq.push({ {-dist[next][remain - ncut], remain - ncut}, next });
			}
		}
	}
	cout << res << '\n';
}

// 한 섬에서 다른 섬까지 종이 뗏목을 타고 이동할 때, 각 경로는 각자의 거리와 뗏목 파괴 정도를 가진다. 뗏목을 지키면서 갈 수 있는 최소 거리는?
// 최단 거리의 최댓값에 제한이 있는 다익스트라 - 뗏목 내구도는 우선순위에 영향을 미치지 않는다
// 따라서 기본적으로 다익스트라와 동일하게 풀되, 뗏목이 부서지는 경우에는 다음 경로 탐색을 하지 말아야 함
// 또한 이로 인해 경로가 여러 갈래로 나뉘게 되니, dist 배열을 2차원으로 관리하자 - 섬과 내구도에 대해
// 이 경우에도 다익스트라는 다익스트라니 처음으로 목적지에 도달하는 경우의 수가 최단 거리가 됨

// 따라서 pq 안에서는 현재까지의 거리(최우선 비교), 남은 뗏목 내구도, 현재 위치를 이용해 탐색을 한다
// 만약 현재 남은 내구도 - 해당 길의 내구도가 0 이하가 아니고, 다음 칸의 dist가 새로운 dist보다 작다면 dist 갱신 후 해당 칸 이동하기