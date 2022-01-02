// 세진 바이러스
// https://www.acmicpc.net/problem/15783

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> board[100001], board_inv[100001];
stack<int> st;
bool visit[100001];
int n, m;

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
	for (int i : board[p]) {
		if (!visit[i])
			dfs_inv(i);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board_inv[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i])
			dfs(i);
	}
	memset(visit, false, sizeof(visit));
	int res = 0;
	while(!st.empty()) {
		int i = st.top();
		st.pop();
		if (!visit[i]) {
			res++;
			dfs_inv(i);
		}
	}
	cout << res << '\n';
}

// 단방향 파이프로 이어진 n개의 정수 시설 전체에 바이러스를 퍼뜨리러 할 때, 최소로 필요한 바이러스의 수는?

// SCC의 개수를 구하는 문제
// 코사라주에서 SCC의 개수는 역방향 DFS를 돌리기 시작하는 개수 - 따라서 그 횟수를 세어주면 됨