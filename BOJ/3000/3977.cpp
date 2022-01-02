// 축구 전술
// https://www.acmicpc.net/problem/3977

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
vector<int> board[100001], board_inv[100001];
stack<int> st;
bool visit[100001];
int indeg[100001];
int scc[100001];
int sccidx;

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
	scc[p] = sccidx;
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
		for (int i = 0; i <= 100000; i++) {
			board[i].clear();
			board_inv[i].clear();
		}
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			board[a].push_back(b);
			board_inv[b].push_back(a);
		}
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) {
			if (!visit[i])
				dfs(i);
		}
		memset(visit, false, sizeof(visit));
		memset(scc, 0, sizeof(scc));
		sccidx = 0;
		while (!st.empty()) {
			int i = st.top();
			st.pop();
			if (!visit[i]) {
				sccidx++;
				dfs_inv(i);
			}
		}
		memset(indeg, 0, sizeof(indeg));
		for (int i = 0; i < n; i++) {
			for (int j : board[i]) {
				if (scc[i] != scc[j])
					indeg[scc[j]]++;
			}
		}
		int cnt = 0, res = 0;
		for (int i = 1; i <= sccidx; i++) {
			if (indeg[i] == 0) {
				res = i;
				cnt++;
			}
		}
		if (cnt > 1)
			cout << "Confused\n";
		else {
			for (int i = 0; i < n; i++)
				if (scc[i] == res)
					cout << i << '\n';
		}
		cout << '\n';
	}
}

// 축구에서 선수들에게 한 지역에서 다른 지역으로 움직이도록 지령을 내릴 때, 시작점이 될 수 있는 곳은?

// 지점끼리 단방향 그래프로 이어져있는 형태 - SCC
// 다른 지역들로 이어지는 시작 지역(시작 SCC)? - SCC간 indeg를 찾으면 된다
// 각 SCC의 indeg(자신에게 들어오는 SCC의 개수)를 저장하는 배열로 indeg 세어주기
// 코사라주로 각 지역에 대해 SCC 번호를 매긴 다음, 모든 지역을 순회하며 그 지역에서 출발하여 이어지는 모든 지역을 보고 같은 SCC에 연결되어 있지 않으면 이어진 SCC에 indeg 추가
// 한 SCC에서 다른 모든 SCC로 이동이 가능하려면 indeg가 0인 SCC가 딱 하나만 있어야 함 - 2개 이상이면 indeg가 0인 SCC끼리 이동이 불가능하고, 0개일 수는 없음
// 따라서 모든 SCC에 대해 indeg가 0인 SCC 개수를 세어주면서, 그런 SCC를 발견하면 해당 SCC 번호를 저장
// 이후 그러한 SCC의 개수가 2개 이상이면 Confused, 그렇지 않다면 해당 SCC 내에 있는 지역들 모두 출력하기

// SCC간 indeg 측정 - 다른 그래프 문제에서도 잘 써먹을 수 있을 거 같아