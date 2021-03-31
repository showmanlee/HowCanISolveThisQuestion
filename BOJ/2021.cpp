// 최소 환승 경로
// https://www.acmicpc.net/problem/2021

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l;
	cin >> n >> l;
	vector<vector<int>> station(n + 1);
	vector<vector<int>> lines(l + 1);
	for (int i = 1; i <= l; i++) {
		while (true) {
			int p;
			cin >> p;
			if (p == -1)
				break;
			station[p].push_back(i);
			lines[i].push_back(p);
		}
	}
	int start, dest;
	cin >> start >> dest;
	vector<int> visit_station(n + 1, -1);
	vector<bool> visit_line(l + 1);
	queue<pr> q;
	q.push({ start, -1 });
	visit_station[start] = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		for (int i : station[cur]) {
			if (!visit_line[i]) {
				visit_line[i] = true;
				for (int j : lines[i]) {
					if (visit_station[j] == -1) {
						visit_station[j] = dist + 1;
						q.push({ j, dist + 1 });
					}
				}
			}
		}
	}
	cout << visit_station[dest] << '\n';
}

// 여러 개의 노선으로 구성된 지하철에서 한 역에서 다른 역으로 갈 때 필요한 환승의 최소 개수는?

// 역과 노선을 동시에 관리 - 역은 자신이 속한 노선을, 노선은 자신에게 속한 역을 저장
// visit도 역을 위한 것과 노선을 위한 것을 분리
// 이후 bfs를 돌리면서 현재 역이 속한 노선의 역들을 모두 탐색하는데, 이때 탐색하지 않는 노선의 탐색하지 않은 역만 탐색하도록 설정
// 같은 노선의 역에 도착할 때 필요한 환승 개수는 0임에 주의

// 개념적으로는 5214 환승과 같은 문제 - 그런데 목적지 도달 시 탈출 코드로 풀면 실패?
// 그래서 visit_station에 거리를 저장하도록 변경했더니 되더라