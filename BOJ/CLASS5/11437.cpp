// LCA
// https://www.acmicpc.net/problem/11437

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> edges[50001];
int depth[50001];
int parent[50001];

void counting(int n, int c) {
	depth[n] = c;
	for (int i : edges[n]) {
		if (depth[i] == 0) {
			parent[i] = n;
			counting(i, c + 1);
		}
	}
}

int find(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	while (depth[a] > depth[b])
		a = parent[a];
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	counting(1, 1);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << find(a, b) << '\n';
	}
}

// 트리가 주어질 떄, 두 노드의 가장 가까운 공통 조상 구하기
// LCA(Lowest Common Ancestor)를 구하는 기초적인 방법?
// 먼저 트리를 2차원 vector로 입력받은 후, 각 노드의 깊이와 부모 노드 저장하기
// 이후 공통 조상을 구할 두 노드의 깊이가 같아지도록 위치를 조정한 후, 깊이를 하나씩 줄여가며 같은 노드로 모이는 순간에 그 노드를 return