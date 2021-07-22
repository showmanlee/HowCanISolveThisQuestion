// 전력량
// https://www.acmicpc.net/problem/6497

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int group[200001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga < gb)
		group[gb] = ga;
	else
		group[ga] = gb;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int m, n;
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		for (int i = 0; i <= m; i++)
			group[i] = i;
		vector<prr> edges;
		int res = 0;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ c, {a, b} });
			res += c;
		}
		sort(edges.begin(), edges.end());
		for (prr e : edges) {
			int a = e.second.first;
			int b = e.second.second;
			int l = e.first;
			if (finding(a) != finding(b)) {
				unioning(a, b);
				res -= l;
			}
		}
		cout << res << '\n';
	}
}

// 가로등의 수가 다른 n개의 길들로 이어진 m개의 집이 있을 때 가로등을 최소로 켜고 모든 집을 연결할 때 끌 수 있는 가로등의 최대 개수는?

// 일반적인 크루스칼에서는 MST의 길이를 구했으나, 이번에는 MST 생성으로 인해 사라지는 길이를 구해야 한다
// 이는 보드를 받을 때 모든 간선의 합을 미리 구한 뒤, 크루스칼을 돌리며 합에서 선택된 간선의 길이를 빼면 가능
// 따라서 이 문제 역시 일반적인 크루스칼 문제