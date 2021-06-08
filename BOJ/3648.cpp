// 아이돌
// https://www.acmicpc.net/problem/3648

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> board[2001];
vector<vector<int>> scc;
stack<int> st;
int discover[2001], sccidx[2001];
int n, m, idx, di;

int dfs(int p) {
	di++;
	discover[p] = di;
	st.push(p);

	int ret = discover[p];
	for (int i : board[p]) {
		if (discover[i] == -1)
			ret = min(ret, dfs(i));
		else if (sccidx[i] == -1)
			ret = min(ret, discover[i]);
	}
	if (ret == discover[p]) {
		idx++;
		scc.push_back(vector<int>());
		while (true) {
			int t = st.top();
			st.pop();
			sccidx[t] = idx;
			scc[idx].push_back(t);
			if (t == p)
				break;
		}
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (cin >> n) {
		cin >> m;
		memset(sccidx, -1, sizeof(sccidx));
		memset(discover, -1, sizeof(discover));
		for (vector<int>& v : board)
			v.clear();
		scc.clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (a < 0)
				a = -a + n;
			if (b < 0)
				b = -b + n;
			int na = (a > n ? a - n : a + n);
			int nb = (b > n ? b - n : b + n);
			board[na].push_back(b);
			board[nb].push_back(a);
		}
		idx = -1;
		di = -1;
		for (int i = 1; i <= n * 2; i++)
			if (sccidx[i] == -1)
				dfs(i);
		int res = true;
		for (int i = 1; i <= n; i++)
			if (sccidx[i] == sccidx[i + n])
				res = false;
		if (sccidx[1] > sccidx[n + 1])
			res = false;
		cout << (res ? "yes" : "no") << '\n';
	}
}

// 아이돌 오디션에서 심사위원들이 2개의 찬성/반대표를 던지는데, 두 표 중 하나는 결과에 반영되어야 한다
// 그렇다면 심사위원들의 표가 모두 정당하게 반영되고, 또한 그럴 때 1번 참가자는 진출하는가?

// 두 개의 표를 던지는데 그 중 하나는 반영되어야 한다 - 2-SAT
// 거기에 1번 참가자 진출 여부까지 봐야 함 - sccidx[1] < sccidx[!1]
// 따라서 2-SAT을 돌린 뒤, 2-SAT 형성 여부와 1번 노드의 true 여부를 sccidx를 통해 알아내자

// 이번에는 타잔 알고리즘으로 SCC를 돌려보자 - 역방향 dfs를 만들 필요가 없지만 dfs 구현이 까다롭고 discover 배열도 만들어야 함
// dfs 함수에 들어가면 자신이 탐색된 순서에 맞게 자신의 discover 값을 할당하고, 탐색 스택에 자신을 삽입한다
// 이후 dfs 리턴값을 자신의 discover 값으로 두고, 자신과 연결된 모든 노드를 탐색한다
// 이때 탐색한 노드가 아직 탐색되지 않았다면 해당 노드의 dfs 함수 리턴값과, scc에 들어가지 않았다면 해당 노드의 discover 값과 현재 리턴값과 비교해 작은 값으로 리턴값을 갱신한다
// 이 과정에서 리턴값이 갱신되지 않은 경우, 현재 노드를 기점으로 scc를 만든다
// scc를 만드는 방법은 탐색 스택에서 자신이 pop될 때까지 노드를 꺼내 현재 scc에 넣는 것
// 모든 과정을 마치면 리턴값을 return