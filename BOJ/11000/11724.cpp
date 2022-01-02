// 연결 요소의 개수
// https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<bool>>& link, vector<bool>& visit, int k, int n) {
	if (visit[k])
		return false;
	visit[k] = true;
	for (int i = 0; i < n; i++) {
		if (link[k][i] && !visit[i])
			dfs(link, visit, i, n);
	}
	return true;
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

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (!visit[i] && dfs(link, visit, i, n))
			count++;
	}
	cout << count << '\n';
}

// 인접 행렬로 그래프 표현... 그렇게 dfs를 해보자
// 인접 행렬은 v*v의 공간이 필요하기 때문에 잘 쓰지 않는다는 것을 주의