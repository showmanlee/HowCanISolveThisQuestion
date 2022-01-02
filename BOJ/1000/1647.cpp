// 도시 분할 계획
// https://www.acmicpc.net/problem/1647

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int group[100001];

int finding(int p) {
	if (p == group[p])
		return p;
	group[p] = finding(group[p]);
	return group[p];
}

void unioning(int a, int b) {
	int pa = finding(a);
	int pb = finding(b);
	if (pa > pb)
		group[pa] = pb;
	else if (pb > pa)
		group[pb] = pa;

}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<prr> edges(m);
	for (int i = 1; i <= n; i++) 
		group[i] = i;
	for (int i = 0; i < m; i++)
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	sort(edges.begin(), edges.end());
	int cnt = 0, maxx = 0;
	long long res = 0;
	for (prr& e : edges) {
		int cost = e.first;
		int a = e.second.first;
		int b = e.second.second;
		if (finding(a) != finding(b)) {
			unioning(a, b);
			cnt++;
			res += cost;
			maxx = max(maxx, cost);
		}
		if (cnt == n - 1)
			break;
	}
	res -= maxx;
	cout << res << '\n';
}

// n개의 집을 잇는 m개의 도로가 있는 마을을 두 개의 마을로 나눌 때, 분리된 마을의 각 집을 모두 왕래할 수 있고 도로 유지 비용을 최소화하는 경우의 유지 비용은?

// 기본적인 MST 문제 - 다만 완성된 MST를 두 개로 나눠야 함
// 완성된 MST는 n - 1개의 간선이 있기에 그 중 하나를 지우면 트리가 2개로 나눠지게 됨
// 그리고 당연히 MST를 구성하는 간선 중 가장 긴 간선을 지우는 것이 이득
// 따라서 크루스칼을 돌리며 MST에 참여하는 간선 중 가장 긴 것을 찾아, 최종 결과값에서 빼주면 그게 답