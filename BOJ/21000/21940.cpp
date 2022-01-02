// 가운데에서 만나기
// https://www.acmicpc.net/problem/21940

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 987654321));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	int k;
	cin >> k;
	vector<int> places(k);
	for (int i = 0; i < k; i++)
		cin >> places[i];
	int resn = 987654321;
	vector<int> resv;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	for (int t = 1; t <= n; t++) {
		int maxx = 0;
		for (int i = 0; i < k; i++)
			maxx = max(maxx, dist[places[i]][t] + dist[t][places[i]]);
		if (maxx < resn) {
			resn = maxx;
			resv.clear();
		}
		if (maxx == resn)
			resv.push_back(t);
	}
	for (int i : resv)
		cout << i << ' ';
	cout << '\n';
}

// m개의 단방향 도로로 이어진 n개의 도시에 k명의 친구들이 한 명씩 살고 있을 때, 친구들의 왕복 거리의 최대가 최소가 되는 집결 도시(들)은?

// 모든 도시에 대한 최단 거리 측정 - 플로이드로 접근
// 우선 보드를 받아 플로이드를 돌려주어 모든 도시 관계의 최단 거리 측정 - 물론 같은 도시간의 거리는 0
// 이후 각 도시를 순서대로 순회하며 왕복 거리의 최댓값을 구해준 후, 현재 결과값과 비교
// 만약 결과값이 갱신되어야 하면 결과를 저장한 배열을 초기화하고 재삽입
// 이렇게 얻은 결과 배열을 출력하면 됨 - 도시를 순서대로 방문했기에 별도의 정렬은 필요없음