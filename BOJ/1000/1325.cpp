// 효율적인 해킹
// https://www.acmicpc.net/problem/1325

#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& trust, vector<bool>& visit, int n, int k) {
	int ret = 1;
	visit[k] = true;
	for (int i : trust[k]) {
		if (!visit[i])
			ret += dfs(trust, visit, n, i);
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> trust(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		trust[b].push_back(a);
	}

	int max = 0;
	vector<int> res(n + 1);
	for (int i = 1; i <= n; i++) {
		vector<bool> visit(n + 1);
		res[i] = dfs(trust, visit, n, i);
		if (res[i] > max)
			max = res[i];
	}
	for (int i = 1; i <= n; i++)
		if (res[i] == max)
			cout << i << ' ';
	cout << '\n';
}

// B->A 방향으로 흐르는 단방향 그래프임에 주의 - 양방향 그래프라면 섬 넓이 찾기와 같은 문제가 됨
// 인접행렬로 연결 처리하면 데이터 낭비니까 컴퓨터당 vector로 저장하자