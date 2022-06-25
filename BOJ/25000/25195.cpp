// Yes or yes
// https://www.acmicpc.net/problem/25195

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pr;
bool res;
bool isThere[100001];

void dfs(vector<vector<int>>& board, int idx, bool seen) {
	if (isThere[idx]) {
		seen = true;
	}
	if (board[idx].size() == 0) {
		if (!seen) {
			res = false;
		}
		return;
	}
	for (int i : board[idx]) {
		dfs(board, i, seen);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
	}
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		int p;
		cin >> p;
		isThere[p] = true;
	}

	res = true;
	dfs(board, 1, false);
	cout << (res ? "Yes" : "yes") << '\n';
}

// 특정 노드들에 팬클럽이 있을 수 있는 단방향 그래프의 1번 노드부터 순회를 시작할 때, 팬클럽을 만나지 않고 단말 노드까지 이동할 수 있는가?

// 이건 bfs보다는 dfs로 풀기 - 한 노드에 여러 노드가 들어올 수 있기 때문에, 방문 순서에 따라 팬클럽을 만나지 않은 루트로 갈 수 있어도 visit에 막힐 수 있음
// 그래프와 팬클럽의 위치를 받고, 1번 노드에서부터 dfs로 내려간다
// 1. 팬클럽을 만나면 seen을 true로 둔다
// 2. 만약 seen이 false인데 더 나아갈 길이 없다면 yes 판정
// 3. 나아갈 길이 있다면 계속 나아가기 - 사이클이 없음이 보장되므로 visit는 챙길 필요 없음
// 이렇게 다 갔는데 yes가 아니라면 Yes 출력하기
// 결국 표시는 Yes or yes - 둘 중에 하나만 골라, 하나만 선택해 어서