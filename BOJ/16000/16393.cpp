// Lost Map
// https://www.acmicpc.net/problem/16393

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int parent[2501];

int finding(int p) {
	if (p == parent[p])
		return p;
	parent[p] = finding(parent[p]);
	return parent[p];
}

void unioning(int a, int b) {
	int pa = finding(a);
	int pb = finding(b);
	if (pa > pb)
		parent[pa] = pb;
	else if (pb > pa)
		parent[pb] = pa;

}
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<prr> edges;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int p;
			cin >> p;
			if (i < j)
				edges.push_back({ p, {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	int cnt = 0, idx = 0;
	while (cnt != n - 1) {
		int cost = edges[idx].first;
		int a = edges[idx].second.first;
		int b = edges[idx].second.second;
		idx++;
		if (finding(a) != finding(b)) {
			unioning(a, b);
			cout << a << ' ' << b << '\n';
			cnt++;
		}
	}
}

// 각 노드 간 최단 거리가 적힌 인접 행렬을 이용해 인접 그래프의 모든 간선 출력하기

// 6091 핑크 플로이드와 동일한 문제 - 여기서는 완전한 형태의 인접 행렬이 주어지고, 간선 단위로 출력해야 한다