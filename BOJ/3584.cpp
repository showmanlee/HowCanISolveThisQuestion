// 가장 가까운 공통 조상
// https://www.acmicpc.net/problem/3584

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<vector<int>> tree(n + 1);
		vector<int> parent(n + 1, -1);
		vector<int> depth(n + 1);
		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			parent[b] = a;
			tree[a].push_back(b);
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (parent[i] == -1) {
				depth[i] = 1;
				q.push(i);
			}
		}
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int i : tree[p]) {
				if (depth[i] == 0) {
					depth[i] = depth[p] + 1;
					q.push(i);
				}
			}
		}
		int a, b;
		cin >> a >> b;
		if (depth[a] < depth[b])
			swap(a, b);
		while (depth[a] > depth[b])
			a = parent[a];
		while (a != b) {
			a = parent[a];
			b = parent[b];
		}
		cout << a << '\n';
	}
}

// 트리 속 두 노드의 공통 조상 찾기
// 11437과 달리 테케가 여러 개지만, 주어지는 관계가 부모-자식 순임이 보장됨(다만 누가 루트인지는 모름)
// 그렇다고는 하지만 부모가 없는 사람이 루트겠지요

// 트리의 최소 공통 조상 찾기
// 1. 트리 입력을 받은 후, 각 노드의 자식들과 부모들을 기록해준다
// 2. 루트 노드부터 시작하여 아래로 내려가면서 해당 노드의 깊이를 기록한다(여기선 bfs로 구현)
// 3. 최종적으로 두 노드가 같은 노드가 될 때까지 노드를 타고 올라간다 