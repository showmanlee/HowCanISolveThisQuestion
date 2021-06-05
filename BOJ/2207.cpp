// 가위바위보
// https://www.acmicpc.net/problem/2207

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, idx;
vector<int> board[20001], board_inv[20001];
stack<int> st;
int sccidx[20001];
bool visit[20001];

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

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 0)
			a = -a + m;
		if (b < 0)
			b = -b + m;
		int na = (a > m ? a - m : a + m);
		int nb = (b > m ? b - m : b + m);
		board[na].push_back(b);
		board_inv[b].push_back(na);
		board[nb].push_back(a);
		board_inv[a].push_back(nb);
	}
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= m * 2; i++)
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
			dfs_inv(i);
		}
	}
	bool res = true;
	for (int i = 1; i <= m; i++)
		if (sccidx[i] == sccidx[i + m])
			res = false;
	cout << (res ? "^_^" : "OTL") << '\n';
}

// 학생 n명이 m번의 가위바위보 중 가위(+) 또는 바위(-)가 언제 나올 것인지 2개씩 예측하여 둘 중 하나만 맞으면 살 수 있을 때, 모두 살 수 있는가?

// 각 학생 당 둘 중 하나만 맞추면 사는데 모두 살아야 한다 - 2-SAT
// SCC를 통한 2-SAT 판정 - 주어진 or 절을 !A -> B, !B -> A와 같은 방식으로 간선을 그어 그래프로 만든 후, SCC 알고리즘을 돌려서 각 노드를 SCC에 소속시킨 후 A와 !A가 같은 SCC에 소속되었는지 확인되면 false
// 따라서 가위는 true, 바위는 false 삼아 그래프 그려서 판정하기 - 가위나 바위만 낼 수 있는 이유는 각 변수를 bool로 만들기 위함
// 이렇게 '모두 살기 위해 둘 중 하나만 맞춰야 한다'는 식의 문제가 나오면 2-SAT을 적용할 수 있음