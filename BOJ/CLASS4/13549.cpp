// 숨바꼭질 3
// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> visit(100001, 987654321);
	priority_queue<pr> pq;
	pq.push({ 0, n });
	visit[n] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int p = pq.top().second;
		pq.pop();
		if (p == k)
			break;
		if (p * 2 <= 100000 && visit[p * 2] > d) {
			visit[p * 2] = d;
			pq.push({ -visit[p * 2], p * 2 });
		}
		if (p + 1 <= 100000 && visit[p + 1] > d + 1) {
			visit[p + 1] = d + 1;
			pq.push({ -visit[p + 1], p + 1 });
		}
		if (p - 1 >= 0 && visit[p - 1] > d + 1) {
			visit[p - 1] = d + 1;
			pq.push({ -visit[p - 1], p - 1 });
		}
	}
	cout << visit[k] << '\n';
}

// 0~100000까지의 선분 상에 나는 n에 있고, 목표가 k에 있다. 목표로 이동하기 위해 +1, -1, *2로 이동할 수 있는데, *2로 이동하면 시간 소모가 없다. 이 때 잡을 수 있는 최소 시간과 그 경로의 수는?
// 1697 숨바꼭질과 달리 *2에 시간 소모가 일어나지 않는다 - 간선마다 가중치가 다르므로 다익스트라를 사용할 수 있음
// bfs를 큐 대신 우선순위 큐로 돌리면 다익스트라와 같은 효과를 볼 수 있음 - 우선순위 큐를 위해 현재 거리도 담는 pair를 사용
// 다익스트라 기반의 최소 거리 탐색이니만큼 visit는 계속 갱신될 수 있도록 설정 - 그러나 도착점에 도달하면 바로 리턴하도록 해도 됨(힙이니까)