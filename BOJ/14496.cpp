// 그대, 그머가 되어
// https://www.acmicpc.net/problem/14496

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, n, m;
	cin >> a >> b >> n >> m;
	vector<vector<int>> board(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x].push_back(y);
		board[y].push_back(x);
	}
	vector<int> dist(n + 1, -1);
	queue<int> q;
	q.push(a);
	dist[a] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == b)
			break;
		for (int i : board[p]) {
			if (dist[i] == -1) {
				dist[i] = dist[p] + 1;
				q.push(i);
			}
		}
	}
	cout << dist[b] << '\n';
}

// 어떤 수에서 다른 수로 바꿀 수 있을 때, a에서 b로 바꾸기 위해 필요한 최소 치환 횟수 구하기

// 출발지와 도착지가 정해져있는 bfs 최단거리 문제 - 모든 간선의 길이가 1인 다익스트라는 bfs와 같음
// 문제에는 직접적으로 나와있지 않지만, 양방향 그래프임에 주의