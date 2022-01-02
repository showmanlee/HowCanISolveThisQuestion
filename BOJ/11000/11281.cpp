// 2-SAT - 4
// https://www.acmicpc.net/problem/11281

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, idx;
vector<int> board[20001], board_inv[20001];
stack<int> st;
vector<vector<int>> scc;
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

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a *= 2;
		if (a < 0)
			a = -a - 1;
		b *= 2;
		if (b < 0)
			b = -b - 1;
		int na = a + (a % 2 == 0 ? -1 : 1);
		int nb = b + (b % 2 == 0 ? -1 : 1);
		board[na].push_back(b);
		board_inv[b].push_back(na);
		board[nb].push_back(a);
		board_inv[a].push_back(nb);
	}
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n * 2; i++)
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
	bool res = true;
	for (int i = 1; i <= n; i++)
		if (sccidx[i * 2] == sccidx[i * 2 - 1])
			res = false;
	cout << res << '\n';
	if (res) {
		for (int i = 1; i <= n; i++)
			cout << (sccidx[i * 2 - 1] < sccidx[i * 2]) << ' ';
		cout << '\n';
	}
}

// n개의 논리 변수가 두 개씩 or로 짝지어져 and로 연결된 식이 주어질 때, 논리 변수들의 값을 조정해 해당 식의 결과를 true로 만들 수 있는가? 있다면 각 변수에 어떤 값을 줘야 하는가?

// SCC 알고리즘을 적용한 2-SAT에서 어떻게 각 변수의 값을 알 수 있을까 - 브루트포스로는 조건을 만족하는 값을 쉽게 찾을 수 있지만
// A와 !A가 같은 SCC에 있으면 에러 - 다른 SCC에 있으면 뭘 넣어도 괜찮음(아래와 동일하게 판정)
// 문제는 다른 SCC에 있으면서 이어진 경우 - 이 경우에는 A와 !A 중 A가 먼저 탐색되었다면 true... 왜?

// 2-SAT 조건(sccidx[a] != sccidx[!a])을 만족하는 상황이라면 A와 !A가 다른 SCC에 있음이 보장됨 - 문제는 두 SCC가 이어져있는가
// SCC를 판정하며 A를 먼저 방문했다면 그래프 상 A에서 !A로 가는 경우는 있을 수 있음 - A SCC -> !A SCC
// 만약 정말로 그런 경우가 존재한다면, !A SCC -> A SCC는 불가능함 - 두 SCC는 단방향으로 연결되어 있음이 보장된 상태(2-SAT 조건)
// 또한 SCC를 순회하며 true -> false인 간선은 존재할 수 없으므로(2-SAT 성립 불가) 먼저 등장한 쪽이 false임이 보장됨

// 어쨌든 이런 방식으로 A가 !A보다 먼저 등장했다면(위상정렬 원리) A는 true가 됨 - 반대라면 false 
// 그런데 나는 3번 문제에서 !A가 먼저 탐색되도록 오도록 풀었음(i * 2 vs i * 2 - 1) - 따라서 여기서는 반대로 !A가 A보다 먼저 등장했다면 true가 됨
// 2-SAT 식에 나온 모든 변수를 뒤집으면 당연히 같은 결과가 나옴 - 그러니까 입력으로 주어진 A가 실제로는 !A였던 것
// 아무튼 간선 그어주는 것, 인덱스 정해주는 것의 순서를 제대로 정해주지 않았다면 저 말이 이해가 되지 않을 수 있음 - 더 많은 2-SAT 문제를 풀면서 차차 이해해나가자