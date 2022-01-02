// 도미노
// https://www.acmicpc.net/problem/4196

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, idx;
vector<int> board[100001], board_inv[100001];
stack<int> st;
vector<vector<int>> scc;
int sccidx[100001];
bool visit[100001];

void dfs(int p) {
	visit[p] = true;
	for (int i : board[p]) {
		if (!visit[i])
			dfs(i);
	}
	st.push(p);
}

void dfs_inv(int p) {
	visit[p] = true;
	scc[idx].push_back(p);
	sccidx[p] = idx;
	for (int i : board_inv[p]) {
		if (!visit[i])
			dfs_inv(i);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		for (int i = 1; i <= 100000; i++) {
			board[i].clear();
			board_inv[i].clear();
		}
		scc.clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			board[a].push_back(b);
			board_inv[b].push_back(a);
		}
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= n; i++)
			if (!visit[i])
				dfs(i);
		memset(visit, false, sizeof(visit));
		memset(sccidx, -1, sizeof(sccidx));
		idx = -1;
		while (!st.empty()) {
			int i = st.top();
			st.pop();
			if (!visit[i]) {
				idx++;
				scc.push_back(vector<int>());
				dfs_inv(i);
			}
		}
		int res = 0;
		for (vector<int>& s : scc) {
			int p = 1;
			for (int i : s) {
				for (int j : board_inv[i]) {
					if (sccidx[i] != sccidx[j])
						p = 0;
				}
			}
			res += p;
		}
		cout << res << '\n';
	}
}

// 한 도미노를 쓰러뜨리면 같이 쓰러지는 도미노의 관계들이 주어질 때, 모든 도미노를 쓰러뜨리기 위해 직접 쓰러뜨려야 하는 도미노의 최소 개수는?

// 단순 사이클이나 dfs 문제는 아님 - 그렇다면 SCC를 도입할 수 있음
// 어떤 도미노 그룹이 SCC로 묶인다면 그 그룹의 도미노는 그룹 중 하나를 쓰러뜨리면 모두 쓰러진다
// 하지만 문제의 답이 SCC의 수는 아님 - 각 SCC가 단방향으로 연결되었을 수도 있다(양방향이면 같은 SCC가 됨)
// 따라서 SCC를 판정한 후 모든 SCC에 대해 연결 여부를 확인해주어야 함
// 각 SCC에 소속된 원소에 대해 해당 원소에서 역방향 그래프로 연결된 원소들을 탐색하여 연결된 원소들이 모두 같은 SCC에 소속되었다면 그 SCC는 독립적이므로 그 안에서 하나를 쓰러뜨려야 함
// 여기서 역방향 그래프로 연결됐다는 건 정방향 그래프에서는 자신에게 오는 다른 원소들을 의미 - 따라서 다른 SCC였다면 그 다른 원소를 건드리면 우리 SCC도 같이 쓰러짐을 의미
// 따라서 이 문제의 답은 최대 'SCC의 개수', 최소 1 - 모든 SCC가 사이클로 연결되면 그 자체로 하나의 SCC가 됨