// Strongly Connected Component
// https://www.acmicpc.net/problem/2150

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> board[10001], board_inv[10001];
stack<int> st;
vector<vector<int>> res;
bool visit[10001];
int v, e, idx;

void dfs(int p) {
	visit[p] = true;
	for (int i : board[p]){
		if (!visit[i])
			dfs(i);
	}
	st.push(p);
}

void dfs_inv(int p) {
	visit[p] = true;
	res[idx].push_back(p);
	for (int i : board_inv[p]) {
		if (!visit[i])
			dfs_inv(i);
	}
}

bool compare(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board_inv[b].push_back(a);
	}
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= v; i++) {
		if (!visit[i])
			dfs(i);
	}
	memset(visit, false, sizeof(visit));
	idx = -1;
	while (!st.empty()) {
		int i = st.top();
		st.pop();
		if (!visit[i]) {
			idx++;
			res.push_back(vector<int>());
			dfs_inv(i);
		}
	}
	for (vector<int>& v : res) 
		sort(v.begin(), v.end());
	sort(res.begin(), res.end(), compare);
	cout << res.size() << '\n';
	for (vector<int>& v : res) {
		for (int i : v)
			cout << i << ' ';
		cout << "-1\n";
	}
}

// 방향 그래프가 주어질 때, 강한 연결 요소(Strongly Connected Component; SCC)의 개수와 각 SCC의 구성 노드 출력하기

// SCC는 그래프에서 서로를 향하는 경로가 항상 존재하면서, 다른 SCC로 향하거나 다른 SCC로 가는 경로 중 하나 이상이 없는 노드 그룹을 말함
// 사이클과는 다른 개념 - SCC의 노드가 항상 사이클 형태를 가지지는 않음
// 어느 SCC에도 속하지 않는 노드 역시 그 노드만의 SCC를 가지고 있다고 판정한다

// SCC를 구하는 방법: 코사라주 vs 타잔 - 둘 다 DFS 기반, 여기서는 코사라주 사용하기
// 코사라주에서는 정방향 그래프와 역방향 그래프, 그리고 별도의 스택을 활용해 SCC를 판정한다
// 1. 정방향 그래프에 노드 번호 순서대로 DFS를 돌리면서, 탐색이 끝나는 순서대로 스택에 노드를 삽입한다
// 2. 역방향 그래프에 스택에 쌓인 순서대로 DFS를 돌리면서, 각 노드에서 출발해 방문한 노드 전체를 SCC로 판정한다
// 두 번의 DFS 모두 독립된 visit 기반으로 이미 방문한 노드는 탐색하지 않도록 하기 - 자세한 것은 코드 형태로 기억하기

// 타잔은 코사라주와 달리 역방향 그래프를 만들 필요가 없고, dfs를 한 번만 돌려도 됨 - 다만 구현 방식이 더 까다로움
// 1. 그래프를 순회하며, 각 노드에 순회한 순서대로 탐색 번호를 부여한다
// 2. 순회 중 자신이 갈 수 있고 SCC에 속하지 않은 노드들의 탐색 번호 중 가장 작은 번호를 return한다
// 3. 최종적으로 return 값과 자신의 탐색 번호가 같아지는 경우, 해당 노드를 기점으로 한 SCC가 완성된 것으로 판정한다
// 나중에 타잔을 써먹을 수 있을 때 써먹어보자

// SCC 내 노드 목록은 물론, 출력되는 SCC 안에서도 정렬이 필요함에 주의 - SCC 내부는 일반적인 sort, 외부는 정렬된 SCC의 첫 노드를 보고 정렬할 수 있도록