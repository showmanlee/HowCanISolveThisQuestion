// 2-SAT - 3
// https://www.acmicpc.net/problem/11280

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
}

// n개의 논리 변수가 두 개씩 or로 짝지어져 and로 연결된 식이 주어질 때, 논리 변수들의 값을 조정해 해당 식의 결과를 true로 만들 수 있는가?

// 이제 n이 10000까지 주어짐 - 더 이상 브포로는 못 풀고, SCC 알고리즘을 도입해야 함
// or 절의 두 변수를 A, B라고 할 때, 모든 A || B 가 true가 되어야 하므로 !A => B, !B => A가 반드시 성립해야 한다
// 이렇게 얻은 2개의 조건식을 SCC 판정용 방향 그래프의 각 간선으로 두고 SCC 알고리즘을 돌린다 - 만약 여기서 같은 SCC로 여러 변수가 포함될 경우, 해당 SCC 전체가 true 또는 false여야 한다
// 만약 이 조건을 만족하지 않는 SCC가 하나라도 발견될 경우 해당 식은 오류

// 여기서는 음수 형태로 !A도 나올 수 있음 - 음수로는 그래프를 그릴 수 없으니 주어진 수의 절댓값에 *2하고 음수라면 음수라면 하나를 빼자
// 이렇게 두 인덱스를 받고, !A와 !B에 대응하는 인덱스를 만든 다음, !A => B, !B => A 간선을 그래프에 그어준다
// 그리고 SCC 알고리즘을 돌려 각 노드(A와 !A)가 어떤 SCC에 소속되어 있는지 표시 - 여기서는 코사라주 사용
// SCC 판정 후, 만약 A와 !A가 같은 SCC에 소속되면 false 판정 - 한 SCC의 원소들은 모두 같은 원소를 가져야 하나 A와 !A는 같은 값을 가질 수 없음