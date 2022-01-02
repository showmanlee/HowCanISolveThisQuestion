// 운동
// https://www.acmicpc.net/problem/1956

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;
	vector<vector<int>> dist(v + 1, vector<int>(v + 1, 987654321));
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	int res = 987654321;
	for (int i = 1; i < v; i++) {
		for (int j = i + 1; j <= v; j++) {
			res = min(res, dist[i][j] + dist[j][i]);
		}
	}
	if (res >= 987654321)
		res = -1;
	cout << res << '\n';
}

// 길이가 다른 단방향 도로로 연결된 여러 개의 마을로 구성된 도시에서 사이클 경로를 찾을 때, 최단 사이클은?

// 한 마을에서 출발해 하나 이상의 다른 마을을 찍고 다시 그 마을로 돌아오는 사이클 경로를 찾는다
// 그런데 명확한 출발점이 주어지지 않기에 모든 마을에 대한 경로를 찾아야 함 - 플로이드
// 플로이드에 기록된 마을간 최단거리 dist에서 dist[a][b] + dist[b][a]는 곧 a-b-a 경로의 사이클 거리라 볼 수 있음
// 따라서 플로이드를 돌린 후 이러한 형태의 거리 중 최솟값을 뽑아주면 그게 답