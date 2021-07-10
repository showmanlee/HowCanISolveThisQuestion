// 작업
// https://www.acmicpc.net/problem/21937

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> tasks(n + 1);
	vector<bool> visit(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		tasks[b].push_back(a);
	}
	int x;
	cin >> x;
	queue<int> q;
	q.push(x);
	visit[x] = true;
	int res = -1;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		res++;
		for (int i : tasks[p]) {
			if (!visit[i]) {
				visit[i] = true;
				q.push(i);
			}
		}
	}
	cout << res << '\n';
}

// 작업 순서도가 주어졌을 때, 어떤 작업을 수행하기 위해 필수적으로 수행해야 하는 작업 개수는?

// 주어지는 작업 순서도를 역으로 저장 - 즉 a->b가 아닌 b->a의 형태로 저장
// 이후 '도착'하는 작업을 받고, 해당 작업부터 bfs를 돌리며 만나는 노드 수를 세준다
// 여기서 자기 자신을 뺀 값이 정답 