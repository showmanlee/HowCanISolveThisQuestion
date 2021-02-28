// ACM Craft
// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, k;
		cin >> n >> k;
		vector<int> times(n + 1), dim(n + 1), res(n + 1, -1);
		vector<vector<int>> route(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> times[i];
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			route[a].push_back(b);
			dim[b]++;
		}
		int w;
		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (dim[i] == 0) {
				q.push(i);
				res[i] = times[i];
			}
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if (p == w)
				break;
			for (int i : route[p]) {
				res[i] = max(res[p] + times[i], res[i]);
				dim[i]--;
				if (dim[i] == 0)
					q.push(i);
			}
		}
		cout << res[w] << '\n';
	}
}

// 건물 건설 소요시간과 테크트리가 주어질 때, 특정 건물을 짓는데 필요한 최소 시간은?
// '위상 정렬'이란 것을 활용해보자 - 트리 진입 차수를 기록하여 그 순서대로 정렬하는 것
// 또한 건물별 최소 소요 시간을 기록해야 한다 - DP
// 큐에 차수가 0인 건물들부터 넣어서 그 건물과 엮인 건물들의 건설 소요 시간을 갱신한다 - max(현재 기록, 앞의 합 + 내 시간)
// 선수 건물들을 모두 충족해야 하므로 max로 계산
// 모든 건물을 다 확인할 필요는 없음 - 큐 커서가 도착지에 도달했다면 탈출