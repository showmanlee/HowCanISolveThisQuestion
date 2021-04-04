// 플로이드
// https://www.acmicpc.net/problem/11404

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int b, e, w;
		cin >> b >> e >> w;
		if (dist[b][e] > w)
			dist[b][e] = w;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (dist[i][j] >= INF ? 0 : dist[i][j]) << ' ';
		cout << '\n';
	}
}

// 편도로 다니는 버스(간선)이 있을 때, 각 도시로 갈 수 있는 최소 거리 구하기
// 플로이드-워셜 알고리즘 문제 - 모든 노드 관계에 대한 최단 경로 구하기
// 간선 정보를 받아 거리 리스트를 갱신하고, 두 노드 사이에 어떤 노드가 거쳐가는 경우가 더 짧을 경우 그걸로 갱신
// 앞으로 INF는 define해서 써야겠다