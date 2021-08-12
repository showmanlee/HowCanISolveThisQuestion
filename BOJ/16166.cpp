// 서울의 지하철
// https://www.acmicpc.net/problem/16166

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<int, vector<int>> station;
	vector<vector<int>> course(n + 1);
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int p;
			cin >> p;
			course[i].push_back(p);
			station[p].push_back(i);
		}
	}
	int dest;
	cin >> dest;
	map<int, int> visit;
	queue<int> q;
	q.push(0);
	visit[0] = -1;
	int res = -1;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == dest) {
			res = visit[p];
			break;
		}
		for (int i : station[p]) {
			for (int j : course[i]) {
				if (visit.count(j) == 0) {
					visit[j] = visit[p] + 1;
					q.push(j);
				}
			}
		}
	}
	if (dest == 0)
		res = 0;
	cout << res << '\n';
}

// 환승역이 있는 노선 체계에서 0번 역에서 도착지로 이동할때 필요한 최소 환승 횟수는?

// 노선과 역을 따져야 하는 bfs 문제
// 각 노선이 가지는 역의 개수나 노선의 개수는 10개 이하지만, 역 번호는 양의 int 범위를 모두 사용
// 따라서 노선도를 구현할 때 map을 활용해야 함 - 각 역에 소속된 노선을 가리키는 map+vector, 각 노선에 포함된 역을 가리키는 2차원 vector, 그리고 각 역별 visit도 map 기반으로
// 처음에 visit[0]은 -1로 시작 - 그리고 큐를 돌리며 해당 역의 소속된 노선에서 방문할 수 있는 미방문한 역들에 visit[p] + 1을 넣고 큐에 삽입하기
// 그렇게 돌리다 도착지에 도달하면 visit[dest], 그렇지 않다면 -1이 답 - 다만 출발지와 도착지가 같을 수 있기에 dest == 0일 경우 결과값을 9으로 설정