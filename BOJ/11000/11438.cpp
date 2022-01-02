// LCA 2
// https://www.acmicpc.net/problem/11438

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> board[100001];
int parent[100001][18];
int depth[100001];
bool visit[100001];

void dfs(int cur, int dep) {
	visit[cur] = true;
	depth[cur] = dep;
	for (int i : board[cur]) {
		if (!visit[i]) {
			parent[i][0] = cur;
			dfs(i, dep + 1);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if ((1 << i) <= depth[a] - depth[b])
			a = parent[a][i];
	}
	if (a == b)
		return a;
	if (a != b) {
		for (int i = 17; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
	}
	return parent[a][0];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i < 18; i++)
		for (int j = 1; j <= n; j++)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}

// 어떤 트리에서 두 노드의 최소 공통 조상 찾기

// LCA 1과 달리 이번에는 노드가 10만 개가 있음
// 만약 LCA 1과 같이 O(n) 기반으로 접근하면 시간 초과 - 편향 트리라면?
// 따라서 O(logn) 기반으로 접근해야 함 - 내 바로 앞의 노드만 저장하는 것이 아닌 2^i번째 노드도 저장하는 것(2차원 배열 형태로)
// 이렇게 만들려면 배열의 폭은 log2(100000) := 18이 되어야 함

// 우선 트리의 dfs를 돌면서 깊이 측정 - 그러면서 parent[i][0]에 직전 노드 기록(2^0 = 1)
// 이렇게 기록한 직전 노드를 통해 2^i번째 부모도 기록할 수 있음 - parent[i][j] = parent[parent[i][j - 1][j - 1] := parent[i][1] = parent[parent[i][0]][0]
// 기록한 부모들을 활용해 lca를 측정하기 위해 두 노드의 높이를 맞춰줘야 함 - n 기반 lca와 비슷하게
// 일단 두 노드의 깊이 차가 2^i 이상이면 a를 2^i번째 노드로 바꾸기 - a와 b 사이 간격을 줄여서 점진적으로 합쳐질 수 있도록
// i를 역순으로 움직이기에 결과적으로 a와 b는 같은 깊이에 위치하게 됨 - 바이너리
// 이렇게 움직인 결과 a와 b가 같은 노드가 되면 a가 lca
// 그렇지 않으면 아까와 동일한 바이너리 기반으로 두 노드를 같은 부모를 가지게 만들기
// 두 노드 간의 범위를 2^i의 역순으로 점점 줄여나가는 것 - 결과적으로 a의 바로 앞 부모가 lca
// 이 원리를 기억해둡시다 - i를 역순으로 돌면 이진수를 탐색하는 것과 동일함