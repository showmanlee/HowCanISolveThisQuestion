// 우주신과의 교감
// https://www.acmicpc.net/problem/1774

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;
typedef pair<double, pr> prr;

int group[1001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga > gb)
		group[ga] = gb;
	else if (gb > ga)
		group[gb] = ga;

}

int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<pr> coord(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> coord[i].first >> coord[i].second;
		group[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		unioning(a, b);
	}
	vector<prr> edges;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double len = sqrt(pow(abs(coord[i].first - coord[j].first), 2) + pow(abs(coord[i].second - coord[j].second), 2));
			edges.push_back({len, {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	int cnt = m;
	double res = 0;
	for (prr& e : edges) {
		double l = e.first;
		int a = e.second.first;
		int b = e.second.second;
		if (finding(a) != finding(b)) {
			unioning(a, b);
			res += l;
			cnt++;
		}
		if (cnt == n - 1)
			break;
	}
	printf("%.2f\n", res);
}

// 2차원 공간에 있는 우주신들 일부가 이미 연결되어 있을 때, 모든 우주신을 연결할 수 있는 최소 비용 출력하기

// 그러니까, 2차원 공간 MST인데 일부 노드가 연결되어 있는 상태라는 것
// 그렇기 때문에 MST 알고리즘으로 남은 간선을 채워줘야 함
// 노드들의 좌표를 받고, 이어진 쌍들을 받아 이들을 이어준다
// 이후 모든 노드쌍에 대해 길이를 측정해 간선 배열에 넣고, 정렬해준다
// 마지막으로 크루스칼을 돌리면서 그어진 간선 수가 n - 1개가 될 때까지 간선을 선택해 결과값에 누적시켜주기