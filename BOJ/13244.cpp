// Tree
// https://www.acmicpc.net/problem/13244

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
bool edges[1001][1001];
bool visit[1001];

bool dfs(int cur, int prev) {
	visit[cur] = true;
	bool ret = true;
	for (int i = 1; i <= n; i++) {
		if (cur == i)
			continue;
		if (edges[cur][i]) {
			if (visit[i] && i != prev)
				return false;
			else if (!visit[i])
				ret = dfs(i, cur);
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		memset(edges, false, sizeof(edges));
		memset(visit, false, sizeof(visit));
		cin >> n;
		int m;
		cin >> m;
		int ec = 0;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (!edges[a][b]) {
				ec++;
				edges[a][b] = true;
				edges[b][a] = true;
			}
		}
		if (ec != n - 1 || (ec == n - 1 && m != n - 1)) {
			cout << "graph\n";
			continue;
		}
		bool res = dfs(1, 0);
		for (int i = 1; i <= n; i++)
			if (!visit[i])
				res = false;
		cout << (res ? "tree" : "graph") << '\n';
	}
}

// 주어진 그래프가 트리인지 아닌지 판정하기

// 그래프가 트리가 되려면 중복되지 않은 간선이 (노드 수 - 1)개여야 하고 사이클이 발생해서는 안 된다
// 여기서는 중복된 간선이 등장할 수 있으나, 간선 정보를 인접행렬로 저장하여 중복 간선을 처리하면 실제 간선 개수를 셀 수 있음
// 또한 여기서는 중복된 간선이 이어진 경우에도 사이클이 있다고 판정하여 그래프가 된다
// 따라서 실제 간선이 n - 1개더라도 입력된 간선이 n - 1이 아닌 경우(트리 모양이지만 중복된 간선이 있는 경우)에도 그래프로 판정해야 함

// 사이클 여부 판정은 dfs를 이용해 판정할 수 있음 - dfs 함수의 매개 변수로는 현재 커서와 이전 커서를 사용
// 트리는 사이클이 없기에 바로 이전에 탐색한 노드가 아니라면 반드시 방문하지 않은 노드여야 함 - 만약 바로 이전에 탐색한 노드가 아님에도 방문한 노드가 보일 경우에는 사이클이 있다는 것
// 또한 하나의 노드에서 시작해 모든 노드를 탐색할 수 있어야 함 - 간선 개수 및 중복 여부를 체크해도 모든 노드가 서로 연결되어 있지 않다면 트리가 아님
// 전자의 경우 dfs 함수 안에서, 후자의 경우 dfs 종료 후 visit 배열 순회를 통해 잡아낸다