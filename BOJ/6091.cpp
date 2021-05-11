// 핑크 플로이드
// https://www.acmicpc.net/problem/6091

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int parent[1025];

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
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int p;
			cin >> p;
			edges.push_back({ p, {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	vector<vector<int>> res(n + 1);
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
			res[a].push_back(b);
			res[b].push_back(a);
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i].size() << ' ';
		sort(res[i].begin(), res[i].end());
		for (int j : res[i])
			cout << j << ' ';
		cout << '\n';
	}
}

// 어떤 트리에 플로이드를 돌린 결과가 주어졌을 때, 이를 다시 인접 리스트 기반 트리 형태로 복원하기

// 트리는 그 특성 상 한 노드에서 다른 노드로 갈 때 왔던 길을 다시 가지 않는 한 최단 거리임이 보장됨
// 플로이드를 돌린 상태의 인접 행렬 = 한 노드와 다른 노드 간의 최단거리 목록
// 플로이드에서 직접적으로 연결되지 않은 두 노드의 최단거리는 [i][k] + [k][j] 꼴로 나타난다
// 따라서 이 문제는 플로이드로 만들어진 완전 그래프에서 MST를 뽑아내는 문제

// 크루스칼을 적용해보자 - 짧은 간선부터 사이클 생기지 않게 차례로 추가해가기
// 양방향 간선이므로 지금까지 썼던 야매 union-find 대신 정식 union-find를 활용
// 간선을 받고 정렬한 후 현재 간선의 두 노드가 같은 그룹에 있지 않다면 해당 노드들을 묶어주며 인접 리스트에 노드 삽입
// 이후 출력 과정에서 한 노드와 연결된 노드들을 정렬 후 출력하기

// 두 노드가 사이클인지 확인하기 전에 find로 parent를 갱신시켜줘야 함에 유의