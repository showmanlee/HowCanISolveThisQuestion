// 우주 탐사선
// https://www.acmicpc.net/problem/17182

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int board[10][10];
int res;
bool visit[10];

void dfs(int cur, int len, int cnt) {
	if (cnt == n) {
		res = min(res, len);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i, len + board[cur][i], cnt + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	for (int l = 0; l < n; l++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][l] > board[i][j] + board[j][l])
					board[i][l] = board[i][j] + board[j][l];
	visit[k] = true;
	res = 987654321;
	dfs(k, 0, 1);
	cout << res << '\n';
}

// 행성간 이동 시간과 출발하는 행성 번호가 주어졌을 때, 중복 방문 허용하여 편도로 모든 행성을 탐사하는데 필요한 최소 시간 구하기

// 중복 방문이 허용되기 때문에 visit 탐색 제한을 무시한 채 dfs를 돌리며 모든 행성을 탐사할 수도 있지만, 이 경우 시간이 너무 오래 걸림
// 하지만 모든 행성간 최단거리를 구해둔다면 모든 간선이 (여러 행성을 거쳤을 수도 있는) 최단거리임이 보장되기에, 전통적으로 한 칸만 탐색하는 dfs 문제로 만들 수 있음
// 이를 위해 탐색 시작 전 플로이드를 돌려 모든 행성 간의 최단거리를 구한다 - 이후 dfs를 돌며 모든 행성을 탐사하고, 걸린 시간 중 가장 작은 값을 출력한다