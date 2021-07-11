// 도로 네트워크
// https://www.acmicpc.net/problem/3176

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int n, m;
vector<pr> board[100001];
int parent[100001][18];
int road_max[100001][18], road_min[100001][18];
int depth[100001];
bool visit[100001];

void dfs(int cur, int dep) {
	visit[cur] = true;
	depth[cur] = dep;
	for (pr p : board[cur]) {
		if (!visit[p.first]) {
			parent[p.first][0] = cur;
			road_max[p.first][0] = road_min[p.first][0] = p.second;
			dfs(p.first, dep + 1);
		}
	}
}

pr lca(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	int minn = 987654321;
	int maxx = -987654321;
	for (int i = 17; i >= 0; i--) {
		if ((1 << i) <= depth[a] - depth[b]) {
			minn = min(minn, road_min[a][i]);
			maxx = max(maxx, road_max[a][i]);
			a = parent[a][i];
		}
	}
	if (a == b)
		return { minn, maxx };
	for (int i = 17; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			minn = min(minn, min(road_min[a][i], road_min[b][i]));
			maxx = max(maxx, max(road_max[a][i], road_max[b][i]));
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	minn = min(minn, min(road_min[a][0], road_min[b][0]));
	maxx = max(maxx, max(road_max[a][0], road_max[b][0]));
	return { minn, maxx };
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	dfs(1, 0);
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			road_min[j][i] = min(road_min[j][i - 1], road_min[parent[j][i - 1]][i - 1]);
			road_max[j][i] = max(road_max[j][i - 1], road_max[parent[j][i - 1]][i - 1]);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pr res = lca(a, b);
		cout << res.first << ' ' << res.second << '\n';
	}
}

// n개의 도시 사이를 유일하게 연결하는 길이가 다른 n-1개의 도로가 있는 네트워크에서, 두 도시 사이의 경로에서 등장하는 도로 길이의 최댓값과 최솟값은?

// n개의 도시는 트리 형태로 연결되어 있음 - 따라서 두 도시 사이의 경로는 유일함
// 두 도시 사이의 경로는 LCA 기반으로 구할 수 있음 - 물론 logn 기반으로
// 그리고 LCA를 구하듯, 해당 부모 노드 사이 도로의 최댓값과 최솟값 역시 구할 수 있음 - 처음 부모 노드 배열을 만들 때 모든 노드를 순회하므로, 같은 원리를 적용할 수 있음
// 우리의 목표는 경로의 길이를 구하는 것이 아니므로, 경로 길이를 잴 필요는 없음

// 우선 부모 노드를 기록하듯 경로 상 최대/최소 간선의 길이를 저장하는 배열을 생성 - 부모 노드 배열과 동일한 크기
// dfs를 돌리며 깊이를 측정하며 바로 전 부모 노드를 기록하는 과정에서 부모 노드와 이어진 간선으로 직전 최대/최소 간선 배열을 초기화
// 이후 2^i번째 부모 노드를 구하는 과정에서 해당 노드까지에서의 최대/최소 간선 노드도 갱신 - 현재 위치(j)와 2^i번째 부모 노드(parent[j][i - 1])와 비교하여
// 마지막으로 lca를 돌리며 만날 수 있는 모든 최대/최소 배열을 활용해 최댓값과 최솟값을 구하고 출력하기
// 높이 맞추는 과정에는 [a][i]를, 보정하는 과정에서는 [a][i]와 [a][i]와 [b][i]를 모두 활용하여
// 쿼리 과정에 두 노드는 서로 다름이 보장됨 - 만약 같다고 한다면 답은 모두 0이 됨