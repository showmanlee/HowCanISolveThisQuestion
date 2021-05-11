// 행성 연결
// https://www.acmicpc.net/problem/16398

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

	int n;
	cin >> n;
	vector<prr> edges;
	for (int i = 0; i < n; i++) {
		group[i] = i;
		for (int j = 0; j < n; j++) {
			int p;
			cin >> p;
			if (i < j)
				edges.push_back({ p, {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	int cnt = 0;
	long long res = 0;
	for (prr& e : edges) {
		int cost = e.first;
		int a = e.second.first;
		int b = e.second.second;
		if (finding(a) != finding(b)) {
			unioning(a, b);
			cnt++;
			res += cost;
		}
		if (cnt == n - 1)
			break;
	}
	cout << res << '\n';
}

// 각 행성을 잇는 양방향 플로우의 관리 비용이 주어질 때, 유지 비용을 최소화한 값은?

// 인접 행렬에서 크루스칼로 MST 만들기
// [i][j] == [j][i]이므로 edges에는 효율을 위해 i < j인 경우에만 담기
// 한 플로우의 관리 비용은 최대 1억 - 따라서 결과가 int에 담기지 않을 수 있음에 주의