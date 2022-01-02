// 서울 지하철 2호선
// https://www.acmicpc.net/problem/16947

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> pr;

int n;
vector<int> board[3001];
bool cycle[3001];
bool visit[3001];
bool dist[3001];

void dfs(int beg, int cur, int cnt) {
	if (beg == cur && cnt >= 2) {
		cycle[cur] = true;
		return;
	}
	visit[cur] = true;
	for (int i : board[cur]) {
		if (!visit[i])
			dfs(beg, i, cnt + 1);
		else if (beg == i && cnt >= 2)
			dfs(beg, i, cnt);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i, i, 0);
	}
	for (int i = 1; i <= n; i++) {
		if (cycle[i])
			cout << 0 << ' ';
		else {
			memset(visit, false, sizeof(visit));
			queue<pr> q;
			q.push({ i, 0 });
			visit[i] = true;
			while (!q.empty()) {
				int p = q.front().first;
				int d = q.front().second;
				q.pop();
				if (cycle[p]) {
					cout << d << ' ';
					break;
				}
				for (int j : board[p]) {
					if (!visit[j]) {
						visit[j] = true;
						q.push({ j, d + 1 });
					}
				}
			}
		}
	}
	cout << '\n';
}

// 2호선과 같은 형태의 순환선과 지선으로 구성된 그래프에서 각 노드에서 순환선으로 가는 거리 출력하기

// 순환선 판정은 dfs, 거리 측정은 bfs
// 우선 매 노드에서 dfs를 돌리면서 순환선 판정하기 - visit는 매 노드마다 초기화 필요(memset)
// dfs 함수는 시작점, 현재 위치, 길이를 매개 변수로 받고, 일반적인 dfs처럼 !visit인 노드를 지속적으로 방문한다 - 길이도 늘려가며
// 이렇게 돌다가 다음 위치가 시작점과 같고, 길이가 2 이상으로 순환선이 성립되는 경우 해당 위치는 순환선 위치에 있는 것이 됨
// 이렇게 순환선 내부에 있는 노드를 표시해준 후, 각 노드에 대해 bfs 수행
// 만약 순환선 내부에 있는 노드라면 bfs 없이 0을 출력하고, 그렇지 않다면 순환선 노드까지의 거리를 bfs로 측정해 출력

// dfs 면에서 아이디어가 필요함 - 여기서는 visit지만 출발점과 같고 순환선인 경우를 캐치해야 함