// 타임머신
// https://www.acmicpc.net/problem/11657

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<pair<int,int>, int> prr;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<prr> route(m);
	vector<long long> dist(n + 1, 9876543210);
	for (prr& p : route)
		cin >> p.first.first >> p.first.second >> p.second;
	dist[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (prr p : route) {
			int s = p.first.first, d = p.first.second, l = p.second;
			if (dist[s] == 9876543210)
				continue;
			if (dist[d] > dist[s] + l)
				dist[d] = dist[s] + l;
		}
	}
	bool fail = false;
	for (prr p : route) {
		int s = p.first.first, d = p.first.second, l = p.second;
		if (dist[s] == 9876543210)
			continue;
		if (dist[d] > dist[s] + l) {
			fail = true;
			break;
		}
	}
	if (fail)
		cout << -1 << '\n';
	else {
		for (int i = 2; i <= n; i++)
			cout << (dist[i] == 9876543210 ? -1 : dist[i]) << '\n';
	}
}

// 타임머신 기능이 섞여 있는 버스들이 있을 때, 1번 도시에서 나머지 도시로 가는 가장 빠른 방법은?
// 음수 가중치 + 단일 시작지 = 벨만포드 - 단방향 그래프에서 벨만포드 적용하기
// 잠깐 벨만포드를 복습하자면
// 노드 - 1만큼 모든 간선을 순회하며 (출발 노드의 최단 거리 + 간선 가중치 < 도착 노드의 최단 거리)인 경우 갱신한다.
// 여기서 음의 사이클 검출을 위해 위의 과정을 한번 더 수행, (출발 노드의 최단 거리 + 간선 가중치 < 도착 노드의 최단 거리)가 있으면 음의 사이클 판정하기
// 사이클이 검출되면 무조건 -1 외치기, 길이 없어도 -1 외치기
// 답 범위는 int지만 계산 중 long long이 될 수 있음에 주의