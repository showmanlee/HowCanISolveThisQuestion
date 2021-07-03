// 상근이의 여행
// https://www.acmicpc.net/problem/9372

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		vector<pr> edges(m);
		for (int i = 0; i < m; i++)
			cin >> edges[i].first >> edges[i].second;
		cout << (n - 1) << '\n';
	}
}

// n개의 국가 사이를 운행하는 m개의 항공편이 주어질 때, 모든 국가를 방문하기 위해 필요한 항공편의 최소 개수 출력하기

// 국가를 노드, 항공편을 간선으로 보면 n개의 노드, m개의 간선을 가진 무방향 그래프로 볼 수 있음
// 그런데 지금 상황은 모든 노드가 서로 이어져 있음이 보장되고, 재귀 간선 역시 없음
// 물론 중복 간선이 있을 수도 있지만, 모든 노드가 서로 이어져있기 때문에 이를 고려할 필요는 없음
// 그리고 모든 노드를 잇는데 필요한 최소 간선 개수는 n - 1개(트리) - 따라서 답은 언제나 n - 1이 됨
// 만약 간선에 가중치가 있었다면 크루스칼을 돌렸어야 했음 - 하지만 지금은 간선이 없으니 트리가 곧 MST