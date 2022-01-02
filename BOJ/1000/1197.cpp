// 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197

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

// 그래프에서 최소 스패닝 트리를 만들고
// 기억을 되살릴 겸 크루스칼을 써보자
// 주어진 간선들을 오름차순 정렬한 후, 사이클이 생기지 않게 간선을 v - 1개 선택한다
// 사이클이 생기지 않게 하기 위해 Union-Find 알고리즘 사용
// - 각 노드에 번호를 부여해 번호가 다른 경우에만 노드를 잇고, 노드가 이어지면 '더 작은 번호'로 '더 큰 번호'를 가진 노드들 모두 갱신
// 다행히 이번에는 O(n)을 돌려도 통과가 됐음

// CLASS 5 개척!