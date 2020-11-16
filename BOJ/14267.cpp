// 내리 칭찬
// https://www.acmicpc.net/problem/14267

#include <iostream>
#include <vector>
using namespace std;

int praise[100001];
vector<vector<int>> ord(100001, vector<int>());

void dfs(int p) {
	for (int i : ord[p]) {
		praise[i] += praise[p];
		dfs(i);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a != -1)
			ord[a].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int p, w;
		cin >> p >> w;
		praise[p] += w;
	}
	dfs(1);
	for (int i = 1; i <= n; i++) 
		cout << praise[i] << ' ';
	cout << '\n';
}

// 내가 가진 칭찬 수치가 부하 직원들에게 모두 더해진다 - 직원 관계는 무조건 트리구조
// 따라서 칭찬을 받을 때마다 DFS를 돌릴 필요는 없고, 내가 받은 칭찬만 기억한 뒤 사장부터 DFS를 돌리며 내 칭찬을 아래에 계속 주면 된다