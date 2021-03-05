// 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> tree(n + 1);
	vector<int> visit(n + 1);
	vector<int> parent(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	visit[1] = true;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i : tree[p]) {
			if (!visit[i]) {
				parent[i] = p;
				visit[i] = true;
				q.push(i);
			}
		}
	}
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}

// 노드를 잇는 간선들이 주어졌을 때, 각 노드의 부모 노드 구하기
// 트리의 형태에 맞게 간선이 주어지나, 간선의 방향은 보장하지 않는다
// 트리를 2차원 vector로 생성하고 BFS를 돌리며 아직 보지 않은 노드의 parent 갱신하기