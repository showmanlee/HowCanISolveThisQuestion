// 거리가 k이하인 트리 노드에서 사과 수확하기
// https://www.acmicpc.net/problem/25516

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n);
	vector<int> apple(n), visit(n, -1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		cin >> apple[i];
	}
	queue<int> q;
	q.push(0);
	int res = apple[0];
	visit[0] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (visit[p] >= k) {
			continue;
		}
		for (int i : board[p]) {
			visit[i] = visit[p] + 1;
			res += apple[i];
			q.push(i);
		}
	}
	cout << res << '\n';
}

// 루트 노드 번호가 0인 트리의 일부 노드에 사과가 있을 때, 루트 노드와의 거리가 k 이하인 노드들에서 얻을 수 있는 사과의 개수는?

// bfs로 거리가 k가 될 때까지 직접 돌려보면 됩니다 - 위에서 아래로 내려가는 거죠
// bfs 넣으면서 사과가 있으면 결과값에 더하고, 이 과정을 가능한 모든 노드에 대해 진행하기