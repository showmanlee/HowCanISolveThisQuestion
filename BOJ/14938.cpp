// 서강그라운드
// https://www.acmicpc.net/problem/14938

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 987654321));
	vector<int> items(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
		dist[i][i] = 0;
	}
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
				if (dist[j][i] > dist[j][k] + dist[k][i])
					dist[j][i] = dist[j][k] + dist[k][i];
			}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int c = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m)
				c += items[j];
		}
		if (c > res)
			res = c;
	}
	cout << res << '\n';
}

// 여러 개의 아이템이 있는 여러 개의 지역이 거리가 다른 양방향 도로로 이어져 있을 때, 특정 활동 반경 안에서 찾을 수 있는 아이템의 최대 개수는?
// '어디'에 떨어져야 아이템을 더 많이 가져갈 수 있을까 - 모든 지역에서의 최단 거리 - 플로이드
// 플로이드는 모든 지역의 최단 거리를 알 수 있지만 n^3 알고리즘이기 때문에 오래 걸림 - 그래도 여긴 100개까지니 괜찮음
