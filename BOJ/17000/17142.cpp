// 연구소 3
// https://www.acmicpc.net/problem/17142

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[51][51];
pr virus[11];
int n, m, v, res;

void bfs() {
	vector<vector<int>> visit(n, vector<int>(n, -1));
	queue<pr> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1)
				visit[i][j] = 0;
			else if (board[i][j] == 3) {
				visit[i][j] = 0;
				q.push({ i, j });
			}
		}
	}
	int ret = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= n)
				continue;
			if (visit[xx][yy] == -1) {
				visit[xx][yy] = visit[x][y] + 1;
				if (board[xx][yy] == 0)
					ret = max(ret, visit[xx][yy]);
				q.push({ xx, yy });
			}
		}
	}
	bool fail = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1)
				fail = true;
		}
	}
	if (fail)
		ret = -1;
	else {
		if (res == -1)
			res = ret;
		else
			res = min(res, ret);
	}
}

void dfs(int count, int last) {
	if (count == m)
		bfs();
	else {
		for (int i = last; i < v; i++) {
			if (board[virus[i].first][virus[i].second] == 2) {
				board[virus[i].first][virus[i].second] = 3;
				dfs(count + 1, i + 1);
				board[virus[i].first][virus[i].second] = 2;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	v = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int p;
			cin >> p;
			if (p == 2)
				virus[v++] = { i, j };
			board[i][j] = p;
		}
	}
	res = -1;
	dfs(0, 0);
	cout << res << '\n';
}

// 연구소의 놓여진 비활성 바이러스 중 m(1~10)개를 활성 상태로 만들 때, 모든 지역에 바이러스를 퍼뜨릴 수 있는 최소 시간은?
// 바이러스 배치는 브루트포스(dfs), 퍼뜨리는 건 BFS
// 연구소 2와 달리 이번에는 선택받지 못한 곳에도 바이러스가 존재함 - 활성(3)과 비활성(2)를 보드에서 분리할 필요가 있음
// 비활성에 활성이 닿으면 활성이 됨 - 없는 곳에 퍼지는 것과 달리 추가 시간이 소모되지 않음
// 그러나 활성화된 바이러스가 확산 활동을 시작하기 위해서는 다음 1초가 필요하므로 결과적으로 적히는 시간은 빈 칸과 같음 - 따라서 bfs 시간 갱신 단계에서 별도의 처리 없이 빈 칸과 동일하게 시간 증가시키기
// 대신 총 소요시간은 빈 칸에 퍼진 것을 기준으로만 계산해야 함 - 비활성 칸은 적힌 시간과 실제 확산 시간과 다르기 때문
// + 소요시간 측정은 적히는 시간 중 최대를 찾는 것이기 때문에 적힌 것보다 1초 덜 계산되는 비활성 칸은 고려하지 않아도 됨
// 그래서 마지막 점검 시점이 아닌 bfs를 돌리는 시점에 소요시간을 계산합니다