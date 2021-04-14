// Crush Fever
// https://www.acmicpc.net/problem/14673

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int m, n;
int res;

void bf(vector<vector<int>> origin, pr point, int score, int count) {
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][j] = origin[i][j];
	queue<pr> q;
	q.push(point);
	int g = board[point.first][point.second];
	board[point.first][point.second] = 0;
	int size = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		size++;
		for (int t = 0; t < 4; t++) {
			int xx = x + dx[t];
			int yy = y + dy[t];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (board[xx][yy] == g) {
				board[xx][yy] = 0;
				q.push({ xx, yy });
			}
		}
	}
	score += size * size;

	if (count == 3) {
		res = max(res, score);
		return;
	}
	for (int j = 0; j < m; j++) {
		for (int i = n - 2; i >= 0; i--) {
			int p = i;
			while (p != n - 1 && board[p][j] != 0 && board[p + 1][j] == 0) {
				swap(board[p][j], board[p + 1][j]);
				p++;
			}
		}
	}
	vector<pr> points;
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && board[i][j] != 0) {
				visit[i][j] = true;
				queue<pr> q;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy])
							continue;
						if (board[x][y] == board[xx][yy]) {
							visit[xx][yy] = true;
							q.push({ xx, yy });
						}
					}
				}
				points.push_back({ i, j });
			}
		}
	}
	if (points.empty()) {
		res = max(res, score);
		return;
	}
	for (pr p : points)
		bf(board, p, score, count + 1);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	vector<pr> points;
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				queue<pr> q;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy])
							continue;
						if (board[x][y] == board[xx][yy]) {
							visit[xx][yy] = true;
							q.push({ xx, yy });
						}
					}
				}
				points.push_back({ i, j });
			}
		}
	}
	res = 0;
	for (pr p : points)
		bf(board, p, 0, 1);
	cout << res << '\n';
}

// n*m 보드에서 뭉쳐있는 블록을 세 번 터뜨려 터뜨릴 때 마다 (블록수 ^ 2)의 점수를 얻을 때, 얻을 수 있는 최고 점수는?

// 보드는 중력이 적용되지만 연쇄는 적용되지 않음 - 블록 종류는 최대 5개, 종류에 따라 점수 차이는 없음
// 브포 + bfs 문제
// 먼저 보드 전체를 bfs로 순회하며 터뜨릴 수 있는 포인트(덩어리 시작점)를 잡는다
// 이후 각 포인트를 터뜨릴 수 있도록 브포 함수로 보내준다

// 현재 보드, 터뜨리는 위치, 현재 점수, 시도 수를 매개변수로 갖는 브포 함수는 다음과 같이 작동
// - 함수 내 자체 보드에 현재 보드를 복사
// - 받는 포인트를 시작으로 bfs를 돌리며 선택한 덩어리의 블록을 터뜨림
// - 터뜨린 블록 수만큼 점수 추가
// - 만약 3번째 시도였을 경우 결과 갱신 후 탈출
// - 떠있는 블록을 아래로 내리기
// - 보드 전체를 bfs로 순회하면 터뜨릴 수 있는 포인트 잡기
// - 만약 그러한 포인트가 없다면(보드가 빈 경우) 결과 갱신 후 탈출, 그렇지 않으면 재귀