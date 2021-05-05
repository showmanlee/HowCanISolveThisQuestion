// 트리
// https://www.acmicpc.net/problem/1068

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> tree(n);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == -1) 
			q.push(i);
		else
			tree[p].push_back(i);
	}
	int e;
	cin >> e;
	int res = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == e)
			continue;
		int cnt = 0;
		for (int i : tree[p]) {
			if (i != e) {
				q.push(i);
				cnt++;
			}
		}
		if (cnt == 0) {
			res++;
			continue;
		}
	}
	cout << res << '\n';
}

// 트리에서 노드 하나를 지웠을 때, 남은 단말 노드의 수는?
// 지워진 노드를 빼고 트리를 순회하면서 단말 노드를 세는 문제 - 물론 생각해줘야 하는 것들이 있음
// 루트 노드가 지워지면 트리 자체가 성립되지 않음 - 따라서 단말 노드도 0개
// 하지만 루트 노드만 남게 되면 루트 노드가 단말 노드가 됨 - 따라서 단말 노드는 1개
// 단말 노드 판정을 위한 자식 노드 수는 직접 세어줘야 함 - 자식 노드가 하나 있더라도 그 노드가 지워질 노드라면 단말 노드가 됨

// 다양한 트리 순회법을 사용할 수 있으나, 여기서는 bfs를 사용 - 내 자식 노드가 지운 노드가 아니라면 큐에 삽입
// 만약 삭제된 노드가 루트 노드라면 큐 탐색 시작하자마자 중단하기