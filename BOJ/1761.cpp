// 정점들의 거리
// https://www.acmicpc.net/problem/1761

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int n;
vector<pr> board[40001];
int depth[40001], length[40001], root[40001];
bool visit[40001];

void dfs(int cur, int dep, int len) {
	visit[cur] = true;
	depth[cur] = dep;
	length[cur] = len;
	for (pr p : board[cur]) {
		if (!visit[p.first]) {
			root[p.first] = cur;
			dfs(p.first, dep + 1, len + p.second);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	while (depth[a] != depth[b])
		a = root[a];
	while (a != b) {
		a = root[a];
		b = root[b];
	}
	return a;
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
	dfs(1, 0, 0);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int res = length[a] + length[b] - (length[lca(a, b)] * 2);
		cout << res << '\n';
	}
}

// 간선의 가중치가 서로 다른 트리에서 선택한 노드 쌍 사이의 거리 출력하기

// n이 4만이라 플로이드 접근은 불가능 - 다익스트라도 불가능에 가까움
// 그래프의 형식이 트리 - 따라서 LCA 기반으로 접근할 수 있음
// 임의의 루트에서 한 노드까지 내려온 길이를 length라고 할 때, 두 노드 사이의 거리는 length[a] + length[b] - (length[lca(a, b)] * 2)
// 즉 루트에서 두 노드까지의 거리의 합에서 중간에 갈라지는 노드(LCA)에서 루트까지 간 거리를 잘라낸 것과 같음
// 따라서 트리를 받고, 1번 노드를 루트 삼아 루트까지의 거리를 구해준 뒤, 쿼리 과정에서 lca를 구하여 구해주면 됨
// 물론 여기서 logn 기반 LCA를 적용하면 실행 시간이 더 줄어들 것 - 나중에 해봐야지