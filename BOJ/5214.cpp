// 환승
// https://www.acmicpc.net/problem/5214

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, m;
	cin >> n >> k >> m;
	vector<vector<int>> nodes(n + 1);
	vector<vector<int>> tubes(m + 1);
	vector<bool> visit_tube(m + 1);
	vector<bool> visit_node(n + 1);
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int p;
			cin >> p;
			nodes[p].push_back(i);
			tubes[i].push_back(p);
		}
	}
	queue<pr> q;
	q.push({ 1, 1 });
	visit_node[1] = true;
	int res = -1;
	while(!q.empty()){
		int p = q.front().first;
		int len = q.front().second;
		q.pop();
		if (p == n) {
			res = len;
			break;
		}
		for (int i : nodes[p]) {
			if (!visit_tube[i]) {
				visit_tube[i] = true;
				for (int j : tubes[i]) {
					if (!visit_node[j]) {
						visit_node[j] = true;
						q.push({ j, len + 1 });
					}
				}
			}
		}
	}
	cout << res << '\n';
}

// n개의 역 중 k개를 하나로 묶는 하이퍼튜브가 m개 있을 때, 1번 역에서 n번 역까지 가는 최소 거리는?

// 역 개수가 10만 개가 주어질 수 있음 - 하이퍼튜브를 분해, 노드를 모두 연결시키면 시간 초과 / 메모리 초과로 탐색 불가
// 하지만 엄연히 노드 탐색이 문제이니만큼 하이퍼튜브와 노드를 동시에 관리할 필요가 있음
// 따라서 탐색은 하이퍼튜브단위로 하되, visit는 하이퍼튜브와 노드를 동시에 돌려야 함
// 이미 방문한 하이퍼튜브라면 통째로 탐색하지 않고, 그렇지 않다면 노드 단위로 탐색 여부 확인

// 노드는 자신이 속한 하이퍼튜브 번호를, 하이퍼튜브는 자신에게 속한 노드 번호를 저장
// 이후 현재 노드와 현재 거리(1부터 시작)을 이용해 큐를 돌린다
// 현재 노드가 속한 탐색되지 않은 하이퍼튜브 중 탐색되지 않은 노드를 다음 큐에 삽입한다
// 최소 거리 구하는 BFS고, 탐색 단위로 노드 단위이기 때문에, 이런 방식으로 처음 n번 역에 진입하면 최소 거리가 됨

// 결과적으로 보면, 서로 연결된 노드가 그룹화되어 '하이퍼튜브'로 명명된 상태에서의 bfs 문제
// 일종의 계층 그래프인 셈
