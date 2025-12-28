// 힘세고 강한 아침
// https://www.acmicpc.net/problem/31566

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 987654321)));
	for (int x = 1; x <= n; x++) {
		for (int i = 1; i <= n; i++) {
			dist[i][i][x] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int b, t, c;
		cin >> b >> t >> c;
		for (int x = 1; x <= n; x++) {
			dist[b][t][x] = c;
		}
	}
	for (int x = 1; x <= n; x++) {
		for (int k = 1; k <= n; k++) {
			if (k == x) {
				continue;
			}
			for (int i = 1; i <= n; i++) {
				if (i == x) {
					continue;
				}
				for (int j = 1; j <= n; j++) {
					if (j == x) {
						continue;
					}
					if (dist[i][j][x] > dist[i][k][x] + dist[k][j][x]) {
						dist[i][j][x] = dist[i][k][x] + dist[k][j][x];
					}
				}
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int s, k, e;
		cin >> s >> k >> e;
		int res = dist[s][e][k];
		if (res >= 987654321) {
			cout << "No\n";
		} else {
			cout << res << '\n';
		}
	}
}

// n개의 노드 간 단방향 가중치가 주어질 때, k번 노드를 지나지 않고 s에서 e로 이동하는 최단거리 구하기