// 두 동전
// https://www.acmicpc.net/problem/16197

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
		if (visit[x1][y1][x2][y2] >= 10)
			continue;
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

// n*m 보드에 두 개의 동전이 있고, 동전을 상하좌우로 움직일 때 벽과 충돌하지 않는 한 독립적으로 움직일 수 있다고 할 때, 두 동전 중 하나만 보드에서 떨어뜨리기 위해 필요한 입력의 수는(최대 10 제한)?

// 더블 bfs - 4차원 visit로 관리해야 하는 문제
// 보드 크기가 최대 20*20 = 400이라 400*400으로 관리해도 됨 - 사실 백트래키을 염두해둔 문제지만 bfs로도 가능
// 우선 보드를 받고, 동전을 입력받으면 빈 칸으로 바꾼 후 위치만 가져오기
// 그 위치들을 기준으로 bfs 탐색 시작 - 두 동전에 대해 상하좌우 이동
// 만약 이동한 위치가 보드를 벗어나는 경우 나간 동전 수를 늘려주고, 벽에 막혔다면 이동 위치를 원위치로 바꾼다
// 이렇게 확정된 최종 위치에서 나간 동전 수가 딱 하나라면 이동한 횟수를 결과값으로 만들어주고, 나간 동전이 없다면 탐색된 경우가 아닐 때 visit 갱신하고 큐에 삽입
// 만약 결과값이 산출된 상태라면 더 이상 탐색을 하지 않고 종료하고, 현재까지 이동한 횟수가 10 이상인 경우에도 탐색하지 않기