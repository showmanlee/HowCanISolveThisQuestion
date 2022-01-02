// 스타트링크
// https://www.acmicpc.net/problem/5014

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	vector<int> visit(f + 1, -1);
	queue<int> q;
	q.push(s);
	visit[s] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		int pu = p + u;
		if (pu >= 1 && pu <= f && visit[pu] == -1) {
			visit[pu] = visit[p] + 1;
			q.push(pu);
		}
		int pd = p - d;
		if (pd >= 1 && pd <= f && visit[pd] == -1) {
			visit[pd] = visit[p] + 1;
			q.push(pd);
		}
	}
	if (visit[g] == -1)
		cout << "use the stairs" << '\n';
	else
		cout << visit[g] << '\n';
}

// f층 건물의 s층에서 g층으로 이동할 때 쓸 엘리베이터가 u층 상승, d층 하강 버튼 밖에 없을 때, 최소 몇 번을 눌러야 g층에 갈 수 있는가(또는 갈 수는 있는가)?
// 1차원 BFS - 위/아래로 가는 칸 수가 정해져 있는 BFS
// 평소의 BFS처럼 큐를 돌려 위쪽/아래쪽을 방문하지 않았다면 거리 갱신하고 큐에 삽입
// 큐를 돌린 후 g층까지의 거리가 갱신되지 않았다면 실패 판정