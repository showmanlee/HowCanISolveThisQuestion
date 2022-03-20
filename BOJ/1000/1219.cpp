// 오민식의 고민
// https://www.acmicpc.net/problem/1219

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, long long> pr;

int main(void) {
	int n, s, e, m;
	cin >> n >> s >> e >> m;
	vector<vector<pr>> board(n);
	vector<long long> earn(n);
	vector<long long> dist(n, 98765432198765);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
	}
	for (int i = 0; i < n; i++) {
		cin >> earn[i];
	}
	dist[s] = -earn[s];
	queue<int> q;
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < n; i++) {
			for (pr p : board[i]) {
				int next = p.first;
				long long len = p.second;
				if (dist[i] != 98765432198765 && dist[next] > dist[i] + len - earn[next]) {
					dist[next] = dist[i] + len - earn[next];
					if (t == n - 1) {
						q.push(i);
					}
				}
			}
		}
	}
	vector<bool> visit(n);
	bool gee = false;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (visit[t]) {
			continue;
		}
		visit[t] = true;
		for (pr p : board[t]) {
			int next = p.first;
			if (next == e) {
				gee = true;
				break;
			}
			if (!visit[next]) {
				q.push(next);
			}
		}
		if (gee) {
			break;
		}
	}
	if (dist[e] == 98765432198765) {
		cout << "gg\n";
	}
	else if (gee) {
		cout << "Gee\n";
	}
	else {
		cout << -dist[e] << '\n';
	}
}
// 통행료가 있는 단방향 도로로 이어진 n개의 도시에 도착해서 벌 수 있는 돈이 주어질 때, 출발지에서 도착지까지 이동하면서 벌 수 있는 최대 액수는?
// 가진 돈이 무한이 될 수 있으면 Gee, 도달할 수 없으며 gg 표시

// 음의 가중치가 있는 그래프에서 최단거리 비슷한 걸 구하는 벨만포드 문제
// 다만 정확히 바라는 건 '가지고 있는 돈의 최댓값'이고, '최단거리'가 아님 - 따라서 음의 사이클이 검출되더라도 Gee 선언이 안 나올 수도 있음
// -> 음의 사이클에 도착지가 연결된다면 Gee지만, 그렇지 않다면 Gee가 아닌 그냥 무시해도 되는 음의 사이클(블랙홀)임
// 우선 계산의 편의를 위해 버는 돈은 빠지는 돈, 빠지는 돈은 버는 돈으로 반전을 해서 생각하자 - 우리는 이제 '가지고 있는 돈의 최솟값'을 구하는 셈\

// 처음에는 벨만포드를 돌려준다 - 원래는 '전체 간선을 돌며 간선 도착지 최단거리가 출발지 최단거리 + 간선 거리보다 길면 갱신하는 과정을 n-1번 반복, 그후 마지막으로 돌면서 같은 상황이 반복되면 음의 사이클 판정'
// 다만 앞서 봤듯이 음의 사이클이 나오더라도 무조건 Gee가 아니기에 벨만포드를 추가로 1번 더 돌려 n번 돌리고, n번째 시점(원래 음의 사이클 검출하는 시점)에서 dist가 갱신된다면(= 음의 사이클이 생긴다면) 별도의 큐에 넣어준다
// 그리고 그 큐를 이용해 bfs를 돌려 해당 사이클이 도착지와 이어지는지 확인한다 - 사이클 안에 있든, 사이클에서 탈출해서 갈 수 있든 도착지와 이어진다면 Gee 판정
// gg 판정은 벨만포드 돌면서 dist가 갱신되지 않았다면 판정 - 두 판정이 모두 아니라면 -dist[e] 출력하기
// 1백만짜리 길로 100개의 노드가 이어지면 int에서 커버하지 못할 수도 있으니 long long으로 관리할 것