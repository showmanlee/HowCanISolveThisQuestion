// 경로 찾기
// https://www.acmicpc.net/problem/11403

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<bool>> edge(n, vector<bool>(n));
	vector<vector<bool>> visit(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int p;
			cin >> p;
			edge[i][j] = p == 1;
		}
	}
	for (int i = 0; i < n; i++) {
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && edge[p][j]) {
					visit[i][j] = true;
					q.push(j);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (visit[i][j] ? 1 : 0) << ' ';
		}
		cout << '\n';
	}
}

// 인접행렬로 주어지는 그래프에서 A에서 B로 가는 링크가 있는지 확인하기
// A에서 A로 이어지는 경로는 A에서 바로 접근하는 것이 아닌 노드를 거쳐 접근해야 함(기본적으로 0)
// BFS가 유리할까