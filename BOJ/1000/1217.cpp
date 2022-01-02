// 하우스 M.D.
// https://www.acmicpc.net/problem/1217

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> board[40001], board_inv[40001];
stack<int> st;
int idx, n, m;
int sccidx[40001];
bool visit[40001];

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
	sccidx[p] = idx;
	for (int i : board_inv[p]) {
		if (!visit[i])
			dfs_inv(i);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		memset(visit, false, sizeof(visit));
		memset(sccidx, -1, sizeof(sccidx));
		for (int i = 0; i <= 40000; i++) {
			board[i].clear();
			board_inv[i].clear();
		}
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (a < 0)
				a = -a + m;
			if (b < 0)
				b = -b + m;
			int na = (a < m ? a + m : a - m);
			int nb = (b < m ? b + m : b - m);
			board[a].push_back(nb);
			board[b].push_back(na);
			board_inv[nb].push_back(a);
			board_inv[na].push_back(b);
		}
		for (int i = 1; i <= m * 2; i++)
			if (!visit[i])
				dfs(i);
		memset(visit, false, sizeof(visit));
		idx = 0;
		while (!st.empty()) {
			int i = st.top();
			st.pop();
			if (!visit[i]) {
				idx++;
				dfs_inv(i);
			}
		}
		int res = 1;
		for (int i = 1; i <= m; i++) {
			if (sccidx[i] == sccidx[i + m]) {
				res = 0;
				break;
			}
		}
		cout << res << '\n';
	}
}

// 동시에 일어나면 안 되는 두 개의 증상들이 나열된 규칙이 주어질 때, 해당 규칙 상에서 살 수 있는 사람이 있는지 판정하기

// 2-SAT - 그런데 이번에는 두 개가 만족하면 안됨
// 그런데 두 개가 만족하면 안 된다는 것은 둘 중 하나만 만족하거나 둘 다 만족하지 말라는 것 - 즉 (!a || !b)와 같다
// 따라서 SCC 그래프를 그려줄 때 !A -> B가 아닌 A -> !B와 같은 형식으로 그래프를 그린다
// 이렇게 SCC 알고리즘을 돌린 후, A와 !A의 sccidx가 동일한 경우 2-SAT이 성립되지 않으므로 무조건 죽게 된다