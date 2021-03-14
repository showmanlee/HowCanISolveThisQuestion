// 여행 가자
// https://www.acmicpc.net/problem/1976

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> route(n + 1);
	vector<int> course(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int p;
			cin >> p;
			if (p == 1)
				route[i].push_back(j);
		}
	}
	for (int& i : course)
		cin >> i;

	vector<int> group(n + 1, 987654321);
	vector<bool> visit(n + 1);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			group[i] = i;
			visit[i] = true;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int p = q.front();
				q.pop();
				for (int j : route[p]) {
					if (!visit[j]) {
						group[j] = i;
						visit[j] = true;
						q.push(j);
					}
				}
			}
		}
	}
	bool res = true;
	int key = group[course[0]];
	for (int i : course)
		if (group[i] != key)
			res = false;
	cout << (res ? "YES" : "NO") << '\n';
}

// 도시 간 연결 현황표가 있다. 도시 여행 계획을 짰을 때, 여행 계획대로 움직일 수 있는가?
// = 여행 계획 안에 있는 도시들이 모두 연결되어 있는가?
// BFS로 덩어리를 체크할 수 있음 - BFS로 연결할 수 있는 모든 곳이 한 덩어리
// 여러 덩어리를 검출하기 위해 BFS 시작점은 1~n까지 순차적으로 돌려야 함