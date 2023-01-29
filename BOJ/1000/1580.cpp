// 위치 바꾸기
// https://www.acmicpc.net/problem/1580

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> prrr;
int dx[9] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};
int dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<vector<vector<int>>>> visit(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
	int sax, say, sbx, sby;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'A') {
				sax = i;
				say = j;
				board[i][j] = '.';
			}
			if (board[i][j] == 'B') {
				sbx = i;
				sby = j;
				board[i][j] = '.';
			}
		}
	}
	queue<prrr> q;
	q.push({{sax, say}, {sbx, sby}});
	visit[sax][say][sbx][sby] = 0;
	bool done = false;
	while (!q.empty()) {
		int ax = q.front().first.first;
		int ay = q.front().first.second;
		int bx = q.front().second.first;
		int by = q.front().second.second;
		int len = visit[ax][ay][bx][by];
		q.pop();
		if (ax == sbx && ay == sby && bx == sax && by == say) {
			cout << len << '\n';
			done = true;
			break;
		}
		for (int i = 0; i < 9; i++) {
			int axx = ax + dx[i];
			int ayy = ay + dy[i];
			if (axx < 0 || axx >= n || ayy < 0 || ayy >= m || board[axx][ayy] == 'X') {
				continue;
			}
			for (int j = 0; j < 9; j++) {
				int bxx = bx + dx[j];
				int byy = by + dy[j];
				if (bxx < 0 || bxx >= n || byy < 0 || byy >= m || board[bxx][byy] == 'X') {
					continue;
				}
				if (axx == bx && ayy == by && bxx == ax && byy == ay) {
					continue;
				}
				if (axx == bxx && ayy == byy) {
					continue;
				}
				if (visit[axx][ayy][bxx][byy] == -1) {
					visit[axx][ayy][bxx][byy] = len + 1;
					q.push({{axx, ayy}, {bxx, byy}});
				}
			}
		}
	}
	if (!done) {
		cout << -1 << '\n';
	}
}

// 8방향으로 이동하거나 이동하지 않을 수 있는 2개의 말을 하나 이상 움직여 한 턴에 두 말이 교차하거나 같은 위치에 있지 않고 서로 반대 말 자리로 이동하는 최소 이동 수는?

// 2개의 말을 이용한 4차원 배열 bfs - 각 말의 위치에 따라 bfs visit를 따로 봐줘야 함
// 각 말은 8방향으로 한칸 이동하거나 아예 움직이지 않을 수도 있음 - 때문에 dx/dy를 9방향으로 만들어준다
// 이후 두 말을 모두 움직여 각 말이 맵 밖이나 벽에 도달한 경우, 두 말이 서로의 이전 위치에 있는 경우, 같은 위치에 있는 경우를 걸러준 뒤 bfs로 이동해준다...