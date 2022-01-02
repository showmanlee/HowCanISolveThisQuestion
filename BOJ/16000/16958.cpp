// 텔레포트
// https://www.acmicpc.net/problem/16958

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	vector<int> special(n + 1);
	vector<pr> pos(n + 1);
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		special[i] = s;
		pos[i] = { x, y };
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (special[i] && special[j])
				dist[i][j] = min(t, abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second));
			else
				dist[i][j] = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}
}

// 좌표 안에 있는 도시 중 일부 도시 간에는 시간이 t만큼 걸리는 텔레포트를 사용해서 이동할 수 있을 때, 주어진 두 도시 간 최소 이동 시간 구하기

// 모든 도시 간의 최단거리 쿼리가 나올 수 있으므로 플로이드를 돌려야 함 - 이를 위해서 기본 거리 맵을 만들어야 함
// 기본적으로 각 도시 간의 거리는 맨해튼 거리 - 텔레포트가 가능한 도시더라도 맨해튼 거리가 더 짧을 수 있기에 이를 고려해줘야 함
// 이렇게 기본 거리 맵을 짠 뒤 플로이드를 돌려 최단 거리 맵을 만든 다음 쿼리에 대응한다