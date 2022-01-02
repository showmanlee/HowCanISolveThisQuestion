// 행성 터널
// https://www.acmicpc.net/problem/2887

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
	vector<pr> x(n + 1), y(n + 1), z(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i].first >> y[i].first >> z[i].first;
		x[i].second = y[i].second = z[i].second = group[i] = i;
	}
	sort(x.begin() + 1, x.end());
	sort(y.begin() + 1, y.end());
	sort(z.begin() + 1, z.end());
	vector<prr> edges;
	for (int i = 2; i <= n; i++) {
		edges.push_back({ x[i].first - x[i - 1].first, {x[i].second, x[i - 1].second} });
		edges.push_back({ y[i].first - y[i - 1].first, {y[i].second, y[i - 1].second} });
		edges.push_back({ z[i].first - z[i - 1].first, {z[i].second, z[i - 1].second} });
	}
	sort(edges.begin(), edges.end());
	int cnt = 0, res = 0;
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

// 3차원 공간에 있는 두 행성을 연결하는 터널을 짓는데 min(|ax - bx|, |ay - by|, |az - bz|)의 비용이 들 때, 모든 행성을 연결하는 최소 비용은?

// 행성을 노드로 한 완전 그래프에서 MST 만드는 문제 - 두 행성의 위치 관계에 따라 간선의 길이가 결정됨
// 다만 행성의 개수가 최대 10만이므로 일일히 모두 계산할 수는 없음
// 그런데 여기서 간선의 길이를 결정하는 축은 차가 최소인 곳 단 하나 - 따라서 행성 좌표를 축 별로 기록해도 간선 길이를 구하는 데는 지장이 없다
// 이를 위해 x, y, z 좌표를 각각의 배열에 따로 저장 - 해당 행성의 좌표와 번호를 기록
// 이후 각 축 배열을 정렬하면 자연스럽게 좌표 간의 간격이 최소가 되는데, 이를 이용해 정식 간선 배열을 만들어줄 수 있다
// 정식 간선 배열을 만든 후, 모든 축 좌표를 순회하며 인접한 두 좌표의 차와 이를 구성하는 두 행성 번호를 기록한다
// 그리고 이를 이용해 크루스칼을 돌리면 답이 나옴