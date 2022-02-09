// 알고리즘 수업 - 너비 우선 탐색 1
// https://www.acmicpc.net/problem/24444

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;

	vector<set<int>> board(n + 1);
	vector<int> visit(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].insert(b);
		board[b].insert(a);
	}
	queue<int> q;
	q.push(r);
	visit[r] = 1;
	int order = 2;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i : board[p]) {
			if (visit[i] == 0) {
				visit[i] = order;
				order++;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << visit[i] << '\n';
	}
}

// 그래프를 너비 우선 탐색할 때 각 노드의 탐색 순서 출력하기

// 노드를 오름차순으로 방문해야 하기 때문에 set으로 설정 - 굳이 set으로 안 해도 정렬해서 처리할 수 있긴 함
// 그 외에는 일반적인 BFS 기본 문제라고 볼 수 있을 듯