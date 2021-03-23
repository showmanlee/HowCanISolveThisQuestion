// 레이저 통신
// https://www.acmicpc.net/problem/6087

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> prrr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int n, m;
	cin >> n >> m;
	int sx = -1, sy, gx, gy;
	vector<vector<char>> board(m, vector<char>(n));
	vector<vector<int>> visit(m, vector<int>(n, 987654321));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'C') {
				if (sx == -1) {
					sx = i;
					sy = j;
				}
				else {
					gx = i;
					gy = j;
				}
			}
		}
	}
	queue<prrr> q;
	for (int i = 0; i < 4; i++) 
		q.push({ {sx, sy}, {i, 0} });
	visit[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int ccnt = cnt + (i == dir ? 0 : 1);
			if (xx < 0 || yy < 0 || xx >= m || yy >= n || board[xx][yy] == '*')
				continue;
			if (visit[xx][yy] >= ccnt) {
				visit[xx][yy] = ccnt;
				q.push({ {xx, yy}, {i, ccnt} });
			}
		}
	}
	cout << visit[gx][gy] << '\n';
}

// 벽이 있는 n*m 공간에서 두 점을 레이저로 연결할 때, 사용해야 하는 거울의 최솟값은?

// bfs지만 최소 거리 조건에 사용된 거울의 수 = 커브의 수도 포함됨
// 평소처럼 visit를 bool로 관리했다면 이미 탐색한 칸에 막혀 '최소 거리'를 탐색하지 못하게 됨
// visit를 int로 관리, 만약 거울을 적거나 같게 쓴 경로의 탐색이 들어갈 경우 visit를 갱신하면서 탐색할 수 있도록 함
// bfs 객체에 현재 레이저의 방향과 거울 사용 횟수를 기록, 다음 탐색점의 방향이 원래 방향과 다른 경우 거울 추가
// 결과는 도착점의 visit가 됨
// 가로/세로 값이 평소와 반대로 주어짐에 주의