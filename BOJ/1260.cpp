// DFS와 BFS
// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge {
	int l, r;
};

void dfs(vector<bool>& visit, vector<edge>& nodes, vector<int>& order, int n) {
	visit[n] = true;
	order.push_back(n);

	vector<int> travel;
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].l == n && !visit[nodes[i].r] && find(travel.begin(), travel.end(), nodes[i].r) == travel.end())
			travel.push_back(nodes[i].r);
		if (nodes[i].r == n && !visit[nodes[i].l] && find(travel.begin(), travel.end(), nodes[i].l) == travel.end())
			travel.push_back(nodes[i].l);
	}
	sort(travel.begin(), travel.end());
	for (int i = 0; i < travel.size(); i++)
		if (!visit[travel[i]])
			dfs(visit, nodes, order, travel[i]);
}

void bfs(vector<bool>& visit, vector<edge>& nodes, vector<int>& order, int n) {
	queue<int> travel;
	travel.push(n);
	while (!travel.empty()) {
		int p = travel.front();
		travel.pop();
		if (visit[p])
			continue;
		visit[p] = true;
		order.push_back(p);

		vector<int> t;
		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i].l == p && !visit[nodes[i].r] && find(t.begin(), t.end(), nodes[i].r) == t.end())
				t.push_back(nodes[i].r);
			if (nodes[i].r == p && !visit[nodes[i].l] && find(t.begin(), t.end(), nodes[i].l) == t.end())
				t.push_back(nodes[i].l);
		}
		sort(t.begin(), t.end());
		for (int i = 0; i < t.size(); i++)
			travel.push(t[i]);
	}
}

int main(void) {
	int n, m, v;
	cin >> n >> m >> v;
	vector<bool> visit_d(n + 1);
	vector<bool> visit_b(n + 1);
	vector<int> order_d;
	vector<int> order_b;
	vector<edge> nodes(m);

	for (int i = 0; i < m; i++) 
		cin >> nodes[i].l >> nodes[i].r;
	
	dfs(visit_d, nodes, order_d, v);
	for (int i = 0; i < order_d.size(); i++)
		cout << order_d[i] << ' ';
	cout << '\n';

	bfs(visit_b, nodes, order_b, v);
	for (int i = 0; i < order_b.size(); i++)
		cout << order_b[i] << ' ';
	cout << '\n';
}

// 두 node 사이에 여러 개의 edge가 있을 수 있고, 동일 단계에서 방문 순서가 오름차순임을 주의
// DFS는 재귀(스택)로 풀고, BFS는 큐로 풀기
// 원형으로 이어져있는 그래프에서 BFS 작동 시 마지막 노드가 두 번 찍힐 수 있음에 주의
// n개의 노드를 모두 순회하지 않을 수 있음에 주의