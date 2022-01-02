// 두 동전 언리미티드
// https://www.acmicpc.net/problem/18170

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> prrr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	int coins = 0;
	int cx1, cy1, cx2, cy2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				board[i][j] = '.';
				coins++;
				if (coins == 1) {
					cx1 = i;
					cy1 = j;
				}
				else {
					cx2 = i;
					cy2 = j;
				}
			}
		}
	}
	vector<vector<vector<vector<int>>>> visit(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
	queue<prrr> q;
	q.push({ {cx1, cy1}, {cx2, cy2} });
	visit[cx1][cy1][cx2][cy2] = 0;
	int res = -1;
	while (!q.empty()) {
		if (res != -1)
			break;
		int x1 = q.front().first.first;
		int y1 = q.front().first.second;
		int x2 = q.front().second.first;
		int y2 = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx1 = x1 + dx[i];
			int yy1 = y1 + dy[i];
			int xx2 = x2 + dx[i];
			int yy2 = y2 + dy[i];
			int status = 0;
			if (xx1 < 0 || yy1 < 0 || xx1 >= n || yy1 >= m)
				status++;
			else if (board[xx1][yy1] == '#') {
				xx1 = x1;
				yy1 = y1;
			}
			if (xx2 < 0 || yy2 < 0 || xx2 >= n || yy2 >= m)
				status++;
			else if (board[xx2][yy2] == '#') {
				xx2 = x2;
				yy2 = y2;
			}
			if (status == 1) {
				res = visit[x1][y1][x2][y2] + 1;
				break;
			}
			else if (status == 0) {
				if (visit[xx1][yy1][xx2][yy2] == -1) {
					visit[xx1][yy1][xx2][yy2] = visit[x1][y1][x2][y2] + 1;
					q.push({ {xx1, yy1}, {xx2, yy2} });
				}
			}
		}
	}
	cout << res << '\n';
}

// n*m 보드에 두 개의 동전이 있고, 동전을 상하좌우로 움직일 때 벽과 충돌하지 않는 한 독립적으로 움직일 수 있다고 할 때, 두 동전 중 하나만 보드에서 떨어뜨리기 위해 필요한 입력의 수는?

// 16197 두 동전에서 이동 횟수 제한이 빠진 문제
// 만약 저 문제를 bfs로 풀었다면 횟수 제한만 빼면 풀림 - 내가 그랬고