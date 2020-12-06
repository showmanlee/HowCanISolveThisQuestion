// 웜홀
// https://www.acmicpc.net/problem/1865

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int begin;
	int end;
	int weight;
	edge(int b, int e, int w) {
		begin = b;
		end = e;
		weight = w;
	}
};

int main(void) {
	int tt = 0;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m, w;
		cin >> n >> m >> w;
		vector<int> dist(n + 1, 987654321);
		vector<edge> edges;
		for (int i = 0; i < m; i++) {
			int b, e, l;
			cin >> b >> e >> l;
			edges.push_back(edge(b, e, l));
			edges.push_back(edge(e, b, l));
		}
		for (int i = 0; i < w; i++) {
			int b, e, l;
			cin >> b >> e >> l;
			edges.push_back(edge(b, e, -l));
		}
		dist[1] = 0;
		for (int i = 0; i < n - 1; i++) {
			for (edge e : edges) {
				if (dist[e.begin] + e.weight < dist[e.end])
					dist[e.end] = dist[e.begin] + e.weight;
			}
		}
		int fail = false;
		for (edge e : edges) {
			if (dist[e.begin] + e.weight < dist[e.end]) {
				fail = true;
				break;
			}
		}
		cout << (fail ? "YES" : "NO") << '\n';
	}
}

// 양의 무방향 간선(도로)와 음의 유방향 간선(웜홀)이 있는 그래프가 주어질 때, 음의 사이클이 존재하는가?
// 벨만-포드 알고리즘 실전 문제 - 음의 간선이 있는 그래프의 최단 경로 찾기
// 1. 모든 간선을 입력한 후, 한 노드에서 출발하는 최단 경로를 기록하는 배열을 생성한다. 초기값은 시작 노드는 0, 나머지는 INF이다.
// 2. 모든 간선을 순회하며 (출발 노드의 최단 거리 + 간선 가중치 < 도착 노드의 최단 거리)일 경우 도착 노드의 최단 거리를 출발 노드의 최단 거리 + 간선 가중치로 갱신한다.
// 3. 2.의 과정을 n - 1번 반복한다.
// 4. 2.의 과정을 한 번 더 돌리면서  (출발 노드의 최단 거리 + 간선 가중치 < 도착 노드의 최단 거리)인 경우를 찾는다. 해당 경우가 등장한다면 해당 노드는 음의 사이클이 있는 경우이다.
// 음의 사이클 검출은 출발 노드로 어떤 노드를 결정하더라도 검출 가능
//  그리고 출발지가 INF인지 검출하지 않아도 됨 - 출발 노드에서 단절된 노드들끼리 사이클이 있을 수도 있기 때문