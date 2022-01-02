// ABCDE
// https://www.acmicpc.net/problem/13023

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> board[2000];
bool visit[2000];
int n, m, res;

void dfs(int beg, int count) {
	if (res == 1)
		return;
	if (count == 4) {
		res = 1;
		return;
	}
	for (int i : board[beg]) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i, count + 1);
			visit[i] = false;
		}
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
		board[b].push_back(a);
	}
	res = 0;
	for (int i = 0; i < n; i++) {
		visit[i] = true;
		dfs(i, 0);
		visit[i] = false;
	}
	cout << res << '\n';
}

// 친구 관계가 주어질 때, A-B, B-C, C-D, D-E가 친구인 꼴이 등장하는가?
// dfs로 친구 5명을 직접 선정하기에는 오래 걸리니까(2000), 친구 관계도를 2차원 vector로 만든 뒤, dfs를 돌려 깊이가 4에 도달하면 정답인 걸로 처리
// 존재 여부만 발견하면 되므로 전역 변수로 선언된 res가 1이 된 경우 dfs를 시도조차 하지 않게 수정
// 그러니까 결과적으로 dfs 문제는 맞음