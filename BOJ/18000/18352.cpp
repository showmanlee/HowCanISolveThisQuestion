// 특정 거리의 도시 찾기
// https://www.acmicpc.net/problem/18352

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, x;
	cin >> n >> m >> k >> x;
	vector<int> length(n + 1, -1);
	length[x] = 0;
	vector<vector<int>> roads(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		roads[a].push_back(b);
	}
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (int i : roads[s]) {
			if (length[i] == -1) {
				length[i] = length[s] + 1;
				q.push(i);
			}
		}
	}
	bool shown = false;
	for (int i = 1; i <= n; i++)
		if (length[i] == k) {
			shown = true;
			cout << i << '\n';
		}
	if (!shown)
		cout << -1 << '\n';
}

// 도시들이 길이가 같은 단방향 도로로 연결되어 있을 때, 한 도시에서 k 시간만에 접근할 수 있는 도시 구하기
// 도로 길이가 같기 때문에 BFS로 최단 거리를 구할 수 있음
// 다만 주어지는 도로의 수가 많으므로 가변 2차원 배열로 도로 정보 저장하기
// BFS를 통해 거리 정보가 -1에서 갱신되는 순간이 바로 최단 거리 - 재갱신 필요 없음!