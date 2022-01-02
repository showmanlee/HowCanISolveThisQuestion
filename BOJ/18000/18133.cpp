// 가톨릭대학교에 워터 슬라이드를??
// https://www.acmicpc.net/problem/18133

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

// n개의 건물 옥상에 한 방향으로 물이 흐르는 워터슬라이드를 m개 깔았을 때, 물을 공급해야 하는 지점의 수는?

// 4196 도미노와 유사한 SCC + in-degree 문제
// 그래프를 받아 SCC를 판정한 후, 각 SCC에 소속된 건물들에 대해 해당 건물로 연결된 건물들 중 다른 SCC에 소속된 건물이 있다면 그 SCC에는 물을 안 넣어줘도 됨
// 워터슬라이드가 연결되지 않은 건물 옥상에도 물을 공급해줘야 함에 주의