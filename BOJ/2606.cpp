// 바이러스
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<bool>>& link, vector<bool>& visit, int k, int n) {
	int ret = 1;
	visit[k] = true;
	for (int i = 0; i < n; i++) {
		if (link[k][i] && !visit[i])
			ret += dfs(link, visit, i, n);
	}
	return ret;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> link(n, vector<bool>(n));
	vector<bool> visit(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		link[a - 1][b - 1] = true;
		link[b - 1][a - 1] = true;
	}
	cout << (dfs(link, visit, 0, n) - 1) << '\n';
}

// 1번과 이어져서 바이러스에 감염되는 컴퓨터 찾기