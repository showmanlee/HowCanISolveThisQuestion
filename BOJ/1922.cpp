// 네트워크 연결
// https://www.acmicpc.net/problem/1922

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;
	vector<int> cycle(v + 1);
	for (int i = 1; i <= v; i++)
		cycle[i] = i;
	vector<prr> edges;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });
	}
	int count = 0, res = 0;
	int index = 0;
	sort(edges.begin(), edges.end());
	while (count < v - 1) {
		int cost = edges[index].first;
		int a = edges[index].second.first;
		int b = edges[index].second.second;
		index++;
		if (cycle[a] != cycle[b]) {
			int m = max(cycle[a], cycle[b]), n = min(cycle[a], cycle[b]);
			for (int i = 1; i <= v; i++)
				if (cycle[i] == m)
					cycle[i] = n;
			count++;
			res += cost;
		}
	}
	cout << res << '\n';
}

// 두 컴퓨터와 연결하는데 필요한 비용이 주어질 때, 비용을 최소로 하여 모든 컴퓨터를 연결한 비용은?
// 최소 신장 트리 문제 - 1197 최소 스패닝 트리와 문제가 똑같음
// 비용이 가장 적은 간선 순서대로 정렬 후 사이클이 생기지 않게 간선 선택하기